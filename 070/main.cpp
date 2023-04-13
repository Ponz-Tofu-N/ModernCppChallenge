/* 70. Approval System*/

/*
 * Rule
 * - the fixed amount payment can be approved by employees depending on their
 * position.
 * - General Employee -> 1000
 * - Team Leader -> 10000
 * - Group Manager -> 100000
 * - President -> more than 100000
 */

#include <iostream>

#include "approval.h"

int main()
{
  auto john = std::make_shared<employee>("john smith",
                                         std::make_unique<employee_role>());

  auto robert = std::make_shared<employee>(
      "robert booth", std::make_unique<team_manager_role>());

  auto david = std::make_shared<employee>(
      "david jones", std::make_unique<department_manager_role>());

  auto cecil = std::make_shared<employee>("cecil williamson",
                                          std::make_unique<president_role>());

  john->set_direct_manager(robert);
  robert->set_direct_manager(david);
  david->set_direct_manager(cecil);

  john->approve(expense{500, "magazins"});
  john->approve(expense{5000, "hotel accomodation"});
  john->approve(expense{50000, "conference costs"});
  john->approve(expense{200000, "new lorry"});
}
