#include <gtest/gtest.h>

#include <chrono>
#include <thread>

#include "../double_buffer.h"

TEST(Rb, db_write)
{
  alg::double_buffer<int> db(5);
  int arr[5] = {1, 2, 3, 4, 5};

  std::thread t([&db, &arr]() {
    for (size_t i = 0; i < 100; i++)
    {
      std::for_each(arr, arr + 5, [&i](int& e) { e += i; });

      db.write(arr, 5);
    }
  });

  int expected[] = {1, 2, 3, 4, 5};

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(0.000001ns);

  std::ostringstream oss;
  db.read(std::ostream_iterator<int>(oss, " "));

  EXPECT_EQ(oss.rdbuf()->str(), "4951 4952 4953 4954 4955 ");
  t.join();
}
