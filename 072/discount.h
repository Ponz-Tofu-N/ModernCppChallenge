#include <string>
#include <vector>

struct customer {
  std::string    name;
  discount_rule *rule;
};

struct article {
  int32_t        id    = -1;
  int32_t        price = -1;
  std::string    name;
  discount_rule *rule;
};

struct order {
  int32_t        id       = -1;
  int32_t        quantity = -1;
  article       *a;
  discount_rule *rule;
};

struct orderlist {
  std::vector<order> orders;
  customer           buyer;
  discount_rule     *rule;
};

class discount_rule {
public:
  virtual double apply(const double price, const uint32_t quantity) = 0;
};

class certain_percentage : public discount_rule {
  double parcentage = 0.0;

public:
  certain_percentage(const double parcentage)
      : parcentage(parcentage){};
  double apply(const double price, const uint32_t quantity) override {
    return parcentage;
  }
};
class quantity_exceeded : public discount_rule {
  double    parcentage   = 0.0;
  // u_int32_t quantity     = 0;
  u_int32_t min_quantity = 0;

public:
  quantity_exceeded(const double parcentage, const uint32_t min)
      : parcentage(parcentage),
        min_quantity(min){};
  double apply(const double price, const uint32_t quantity) override {
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
      : parcentage(parcentage),
        min_amount(min){};
  double apply(const double price, const uint32_t quantity) override {
    return price * quantity >= min_amount ? parcentage : 0.0;
  }
};
class total_amount : public discount_rule {
  double    parcentage = 0.0;
  // u_int32_t total      = 0;
  u_int32_t min_total  = 0;

public:
  total_amount(const double parcentage, const uint32_t min)
      : parcentage(parcentage),
        min_total(min){};
  double apply(const double price, const uint32_t quantity) override {
    return price >= min_total ? parcentage : 0.0;
  }
};