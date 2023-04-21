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

int main() {
  certain_percentage rule1(5);
  quantity_exceeded  rule2(10, 10);
  amount_exceeded    rule3(15, 100);
  total_amount       rule4(5);

  discount_system system;

  system.add_rule(rule1);
  system.add_rule(rule2);
  system.add_rule(rule3);
  system.add_rule(rule4);
}
