#include <iostream>
#include <vector>

struct notification {
  enum class change_type { ADD, DELETE, ASSIGN, CLEAR };

  change_type type;
  size_t      index = 0;

  notification() = delete;
  notification(change_type type, size_t index)
      : type(type),
        index(index){};
};

class observer {
  virtual std::string log_type(const notification &n) const {
    switch (n.type) {
      case notification::change_type::ADD:
        return "add";
      case notification::change_type::ASSIGN:
        return "assign";
      case notification::change_type::DELETE:
        return "delete";
      case notification::change_type::CLEAR:
        return "clear";
      default:
        return "";
    }
  };

public:
  virtual void changed(const notification &n) const {
    std::cout << log_type(n) << " at " << n.index << std::endl;
  };
};

template <typename T>
class observable_vector {
  std::vector<observer *> observers;
  std::vector<T>          data;

public:
  observable_vector() = default;
  observable_vector(std::initializer_list<T> list)
      : data(std::vector<T>(list)) {
  }
  void operator=(observable_vector const &other) {
    data      = other.data;
    observers = other.observers;

    const notification n{notification::change_type::ASSIGN, data.size()};
    std::for_each(observers.begin(), observers.end(), [&n](const auto &o) {
      o->changed(n);
    });
  }

  T &operator[](const size_t index) {
    return data[index];
  }

  // indexからobserver を取得、テスト用
  observer *get_observer(const size_t index) {
    return observers[index];
  }

  // 　 オブザーバが登録されているか確認する
  bool is_observers_empty() const {
    return observers.empty();
  }

  // 指定のオブザーバを削除する
  void remove_observer(observer *o) {
    auto found =
        std::find_if(observers.begin(), observers.end(), [&o](auto shr_p) {
          return shr_p == o;
        });
    if (found != observers.cend()) {
      observers.erase(found);
    }
  }

  // 指定のオブザーバを追加
  void add_observer(observer *o) {
    observers.emplace_back(o);
  }

  // Vectorの関数群
  void push_back(T const &element) {
    data.push_back(element);
    const notification n{notification::change_type::ADD, data.size() - 1};
    std::for_each(observers.begin(), observers.end(), [&n](const auto &o) {
      o->changed(n);
    });
  };
  void pop_back() {
    data.pop_back();

    const notification n{notification::change_type::DELETE, data.size()};
    std::for_each(observers.begin(), observers.end(), [&n](const auto &o) {
      o->changed(n);
    });
  };
  void clear() {
    const notification n{notification::change_type::CLEAR, data.size()};
    std::for_each(observers.begin(), observers.end(), [&n](const auto &o) {
      o->changed(n);
    });

    data.clear();
  };
  size_t size() {
    return data.size();
  }
};