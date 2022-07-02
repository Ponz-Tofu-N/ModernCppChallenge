#include <gtest/gtest.h>

#include "../alg.h"

TEST(Rb, rb1)
{
  alg::ring_buffer<int> rb(5);

  rb.push(1);
  rb.push(2);
  rb.push(3);

  auto itr_b = rb.begin();
  auto itr_e = rb.end();

  EXPECT_EQ(*itr_b, 1);
  EXPECT_EQ(*(itr_e - 1), 3);

  rb.push(4);
  rb.push(5);
  rb.push(6);

  itr_b = rb.begin();
  itr_e = rb.end();

  EXPECT_EQ(*itr_b, 2);
  EXPECT_EQ(*(itr_e - 1), 6);
}

TEST(Rb, rb2)
{
  alg::ring_buffer<int> rb(5);

  rb.push(1);
  rb.push(2);
  rb.push(3);
  rb.push(4);
  rb.push(5);
  rb.push(6);

  auto itr_b = rb.begin();
  auto itr_e = rb.end();

  EXPECT_EQ(*itr_b, 2);
  EXPECT_EQ(*(itr_e - 1), 6);
}

TEST(Rb, end)
{
  alg::ring_buffer<int> rb(5);

  rb.push(1);
  rb.push(2);
  rb.push(3);
  rb.push(4);
  rb.push(5);
  rb.push(6);

  auto itr_e = rb.end();

  EXPECT_THROW(*itr_e, std::out_of_range);
}

TEST(Rb, empty_begin)
{
  alg::ring_buffer<int> rb(5);

  auto itr_b = rb.begin();

  EXPECT_THROW(*itr_b, std::out_of_range);
}