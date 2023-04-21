#include <gtest/gtest.h>

#include <tuple>

#include "../discount.h"

// class discount_rule
// class certain_percentage
// class quantity_exceeded
// class amount_exceeded
// class total_amount

class DiscountTest : public ::testing::Test {
protected:
  std::unique_ptr<certain_percentage> cp;
  std::unique_ptr<quantity_exceeded> qe;
  std::unique_ptr<amount_exceeded> ae;
  std::unique_ptr<total_amount> ta;

  double price = 100.0;
  double quantity = 10.0;
};

TEST_F(DiscountTest, CertainPercentageTest) {
  double parcentage = 0.05;

  cp = std::make_unique<certain_percentage>(parcentage);
  EXPECT_EQ(parcentage, cp->apply(price, quantity));
}

TEST_F(DiscountTest, QuantityExceededTest) {
  double parcentage = 0.05;

  qe = std::make_unique<quantity_exceeded>(parcentage, 9.0);
  EXPECT_EQ(parcentage, qe->apply(price, quantity));

  qe = std::make_unique<quantity_exceeded>(parcentage, 15.0);
  EXPECT_EQ(0.0, qe->apply(price, quantity));
}

TEST_F(DiscountTest, AmountExceededTest) {
  ae = std::make_unique<amount_exceeded>(0.05, 1000.0);
  EXPECT_EQ(0.05, ae->apply(price, quantity));

  ae = std::make_unique<amount_exceeded>(0.05, 10000.0);
  EXPECT_EQ(0.0, ae->apply(price, quantity));
}

TEST_F(DiscountTest, TotalAmountTest) {
  ta = std::make_unique<total_amount>(0.05, 100.0);
  EXPECT_EQ(0.05, ta->apply(price, quantity));

  ta = std::make_unique<total_amount>(0.05, 10000.0);
  EXPECT_EQ(0, ta->apply(price, quantity));
}