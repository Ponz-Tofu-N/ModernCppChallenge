#include <gtest/gtest.h>

#include <tuple>

#include "../observable_vector.h"

class ObservableVectorTest : public ::testing::Test {
protected:
  observable_vector<int> ov;
};

TEST_F(ObservableVectorTest, AddObserver) {
  auto o = new observer();

  ov.add_observer(o);
  EXPECT_EQ(o, ov.get_observer(0));
}

TEST_F(ObservableVectorTest, RemoveObserver) {
  auto o = new observer();

  ov.add_observer(o);
  EXPECT_FALSE(ov.is_observers_empty());

  ov.remove_observer(o);
  EXPECT_TRUE(ov.is_observers_empty());
}

class ObserverTest
    : public testing::TestWithParam<
          std::tuple<notification::change_type, size_t, std::string>> {};

TEST_P(ObserverTest, ObserverChanged) {
  auto p = GetParam();

  auto          change_type = std::get<0>(p);
  auto          index       = std::get<1>(p);
  auto          expected    = std::get<2>(p);
  observer     *o           = new observer();
  notification *n           = new notification(change_type, index);

  testing::internal::CaptureStdout();  // 標準出力キャプチャ開始
  o->changed(*n);

  delete n;
  delete o;

  EXPECT_STREQ(
      expected.c_str(), testing::internal::GetCapturedStdout().c_str()
  );
}

INSTANTIATE_TEST_SUITE_P(
    ObserverTestParams,
    ObserverTest,
    testing::Values(
        std::make_tuple(notification::change_type::ADD, 1, "add at 1\n"),
        std::make_tuple(notification::change_type::ASSIGN, 1, "assign at 1\n"),
        std::make_tuple(notification::change_type::DELETE, 1, "delete at 1\n"),
        std::make_tuple(notification::change_type::CLEAR, 1, "clear at 1\n")
    )
);

TEST_F(ObservableVectorTest, PushBackTest) {
  auto o = new observer();

  ov.add_observer(o);

  testing::internal::CaptureStdout();  // 標準出力キャプチャ開始

  ov.push_back(1);
  ov.push_back(2);
  ov.push_back(3);

  EXPECT_STREQ(
      "add at 0\nadd at 1\nadd at 2\n",
      testing::internal::GetCapturedStdout().c_str()
  );
}
TEST_F(ObservableVectorTest, PopBackTest) {
  auto o = new observer();

  ov.add_observer(o);

  ov.push_back(1);
  ov.push_back(2);
  ov.push_back(3);

  testing::internal::CaptureStdout();  // 標準出力キャプチャ開始

  ov.pop_back();
  ov.pop_back();
  ov.pop_back();

  EXPECT_STREQ(
      "delete at 2\ndelete at 1\ndelete at 0\n",
      testing::internal::GetCapturedStdout().c_str()
  );
}

TEST_F(ObservableVectorTest, AssignTest) {
  auto o = new observer();

  observable_vector<int> ov_other;
  ov_other.add_observer(o);

  ov_other.push_back(4);
  ov_other.push_back(5);
  ov_other.push_back(6);

  testing::internal::CaptureStdout();  // 標準出力キャプチャ開始

  ov = ov_other;

  EXPECT_STREQ("assign at 3\n", testing::internal::GetCapturedStdout().c_str());
}

TEST_F(ObservableVectorTest, ClearTest) {
  auto o = new observer();

  ov.add_observer(o);

  observable_vector<int> ov_other;

  ov.push_back(4);
  ov.push_back(5);
  ov.push_back(6);

  testing::internal::CaptureStdout();  // 標準出力キャプチャ開始

  ov.clear();

  EXPECT_EQ(0, ov.size());
  EXPECT_STREQ("clear at 3\n", testing::internal::GetCapturedStdout().c_str());
}