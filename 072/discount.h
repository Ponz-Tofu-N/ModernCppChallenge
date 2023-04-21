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
  int32_t id = -1;
  std::string name;
  int32_t price = -1;
  discount_rule *rule;
};

struct order {
  article a;
  int32_t quantity = -1;
  discount_rule *rule;
};

struct orderlist {
  int32_t id = -1;
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
  // u_int32_t quantity     = 0;
  u_int32_t min_quantity = 0;

public:
  quantity_exceeded(const double parcentage, const uint32_t min)
      : parcentage(parcentage), min_quantity(min){};
  double apply(const double price, const double quantity) override {
    return quantity >= min_quantity ? parcentage : 0.0;
  }
};
class amount_exceeded : public discount_rule {
  double parcentage = 0.0;
  // double    price      = 0;
  // u_int32_t quantity   = 0;
  double min_amount = 0.0;

public:
  amount_exceeded(const double parcentage, const uint32_t min)
      : parcentage(parcentage), min_amount(min){};
  double apply(const double price, const double quantity) override {
    return price * quantity >= min_amount ? parcentage : 0.0;
  }
};
class total_amount : public discount_rule {
  double parcentage = 0.0;
  // u_int32_t total      = 0;
  u_int32_t min_total = 0;

public:
  total_amount(const double parcentage, const uint32_t min)
      : parcentage(parcentage), min_total(min){};
  double apply(const double price, const double quantity) override {
    return price >= min_total ? parcentage : 0.0;
  }
};

class price_calculator {
private:
  orderlist *ol;

public:
  price_calculator(/* args */){};
  ~price_calculator(){};

  double calculate_price() const { return 0.1; };
};
