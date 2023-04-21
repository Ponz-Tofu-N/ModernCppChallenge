#include <string>
#include <vector>

class discount_rule {
public:
  virtual double apply(const double price, const double quantity) = 0;
};

struct customer {
  std::string name;
  discount_rule *rule;
};

struct article {
  uint32_t id = -1;
  std::string name;
  double price = -1;
  discount_rule *rule;
};

struct order {
  article a;
  double quantity = -1;
  discount_rule *rule;
};

struct orderlist {
  uint32_t id = -1;
  customer *buyer;
  std::vector<order> orders;
  discount_rule *rule;
};

class certain_percentage : public discount_rule {
  double parcentage = 0.0;

public:
  certain_percentage(const double parcentage) : parcentage(parcentage){};
  double apply(const double price, const double quantity) override {
    return parcentage;
  }
};

class quantity_exceeded : public discount_rule {
  double parcentage = 0.0;
  // u_double quantity     = 0;
  double min_quantity = 0;

public:
  quantity_exceeded(const double parcentage, const double min)
      : parcentage(parcentage), min_quantity(min){};
  double apply(const double price, const double quantity) override {
    return quantity >= min_quantity ? parcentage : 0.0;
  }
};
class amount_exceeded : public discount_rule {
  double parcentage = 0.0;
  // double    price      = 0;
  // u_double quantity   = 0;
  double min_amount = 0.0;

public:
  amount_exceeded(const double parcentage, const double min)
      : parcentage(parcentage), min_amount(min){};
  double apply(const double price, const double quantity) override {
    return price * quantity >= min_amount ? parcentage : 0.0;
  }
};
class total_amount : public discount_rule {
  double parcentage = 0.0;
  // u_double total      = 0;
  double min_total = 0;

public:
  total_amount(const double parcentage, const double min)
      : parcentage(parcentage), min_total(min){};
  double apply(const double price, const double quantity) override {
    return price >= min_total ? parcentage : 0.0;
  }
};

class price_calculator {
public:
  price_calculator(/* args */){};
  ~price_calculator(){};

  double calculate_price(const orderlist &ol) const {
    double total_price = 0.0;
    double total_quantity = 0.0;

    for (auto &&order : ol.orders) {
      auto price = order.a.price;
      auto quantity = order.quantity;
      auto discount = 0.0;

      total_price += price * quantity * (1.0 - discount);
      total_quantity += quantity;

      if (order.a.rule) {
        total_price *= (1 - order.a.rule->apply(total_price, total_quantity));
      }

      if (order.rule) {
        total_price *= (1 - order.rule->apply(total_price, total_quantity));
      }
    }

    if (ol.buyer->rule) {
      total_price *= (1 - ol.buyer->rule->apply(total_price, total_quantity));
    }

    if (ol.rule) {
      total_price *= (1 - ol.rule->apply(total_price, total_quantity));
    }

    return total_price;
  };
};
