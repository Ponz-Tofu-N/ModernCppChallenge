#include "approval.h"

#include <iostream>

void employee::approve(expense const &e)
{
  if (e.cost() > own_role->limit())
  {
    direct_manager->approve(e);
    return;
  }

  std::cout << name << " approved " << e.description() << ": " << e.cost()
            << std::endl;
};
void employee::set_direct_manager(std::shared_ptr<employee> dm)
{
  if (dm)
  {
    direct_manager = dm;
  }
};

size_t employee_role::limit() { return 1000; }
size_t team_manager_role::limit() { return 10000; }
size_t department_manager_role::limit() { return 100000; }
size_t president_role::limit() { return 1000000; }
