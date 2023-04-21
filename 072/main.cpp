/* 72. Discount System*/

/*
 * Rule
 * - Discounting Ststem to be able to apply some discount rules for customers,
 * articles and orders.
 *    - Discount a certain pacentage.
 *    - Discount if defined quantity exceeded.
 *    - Discount if defined amount exceeded.
 *    - Discount for the total amount.
 */

#include <iostream>

#include "discount.h"

static void print_price(price_calculator const &pc) {
  std::cout << pc.calculate_price() << std::endl;
};

int main() {
  certain_percentage rule1(0.1);
  quantity_exceeded rule2(0.15, 10);
  amount_exceeded rule3(0.05, 100.0);
  total_amount rule4(0.05, 100);

  customer c1{"default", nullptr};
  customer c2{"john", &rule1};
  customer c3{"joane", &rule3};

  article a1{1, "pen", 5, nullptr};
  article a2{2, "expensive pen", 15, &rule1};
  article a3{3, "scissors", 10, &rule2};

  orderlist o1{101, &c1, {{a1, 1, nullptr}}, nullptr};
  orderlist o2{102, &c2, {{a1, 1, nullptr}}, nullptr};
  orderlist o3{103, &c1, {{a2, 1, nullptr}}, nullptr};
  orderlist o4{104, &c2, {{a2, 1, nullptr}}, nullptr};
  orderlist o5{105, &c1, {{a3, 1, nullptr}}, nullptr};
  orderlist o6{106, &c1, {{a3, 15, nullptr}}, nullptr};
  orderlist o7{107, &c3, {{a3, 15, nullptr}}, nullptr};
  orderlist o8{108, &c3, {{a2, 20, &rule1}}, nullptr};
  orderlist o9{109, &c3, {{a2, 20, &rule1}}, &rule4};
}
