/* 66. Customer Service*/

/*
 * Rule
 *  - customers takes a ticket with a service number and the order.
 *  - customers get a service in the order of ticket number.
 *  - customers get a service same as the number on the ticket.
 *  - there are 3 services and 3 desks for each service.
 */
#include <queue>
#include <thread>

#include "context.h"
#include "customer.h"
#include "logger.h"
#include "store.h"

int main(int argc, char const* argv[])
{
  constexpr unsigned int MAX_CUSTOMERS = 30;

  std::priority_queue<customer> customers;
  bool store_open = true;
  machine m;
  std::mutex permission;

  // チケットを発券する
  std::thread t([&]() {
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
      permission.lock();
      customers.push(m.ticketing());
      m.next();

      permission.unlock();

      context::instance().coming();
    }

    store_open = false;
  });

  // デスク環境を構築する
  std::vector<std::thread> desks;
  for (int desk_id = 1; desk_id <= 3; desk_id++)
  {
    desks.emplace_back([desk_id, &customers, &store_open, &permission]() {
      desk d;
      while (!customers.empty() || store_open)
      {
        std::lock_guard lock(permission);

        if (customers.empty())
          continue;

        auto c = customers.top();
        customers.pop();

        permission.unlock();

        Logger::instance().log(
            std::string("Handling ticket number "), std::to_string(c.ticket()),
            std::string(" on desk "), std::to_string(desk_id));

        std::cout << "size: " << customers.size() << "\n";

        d.process();
      }
    });
  }

  for (auto&& desk : desks)
  {
    desk.join();
  }

  t.join();

  return 0;
}
