#include "Queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throw_when_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_push)
{
  TQueue<int> q(5);
  ASSERT_NO_THROW(q.Put(4));
}

TEST(TQueue, can_shift)
{
  TQueue<int> q(5);
  q.Put(4);
  q.Put(2);
  EXPECT_EQ(4, q.Get());
}

TEST(TQueue, can_not_shift_empty_queue)
{
  TQueue<int> q(5);
  ASSERT_ANY_THROW(q.Get(););
}



TEST(TQueue, can_not_push_full_queue)
{
  TQueue<int> q(5);
  q.Put(2);
  q.Put(2);
  q.Put(2);
  q.Put(2);
  q.Put(2);
  ASSERT_ANY_THROW(q.Put(2));
}

TEST(TQueue, can_fetch_right_order)
{
  TQueue<int> q(5);
  q.Put(4);
  q.Put(2);
  q.Put(8);
  EXPECT_EQ(4, q.Get());
  EXPECT_EQ(2, q.Get());
  EXPECT_EQ(8, q.Get());
}

TEST(TQueue, can_fetch_all_queue)
{
  TQueue<int> q(5);
  q.Put(4);
  q.Put(2);
  q.Put(8);
  EXPECT_EQ(4, q.Get());
  EXPECT_EQ(2, q.Get());

  q.Put(-5);
  q.Put(42);

  EXPECT_EQ(8, q.Get());
  EXPECT_EQ(-5, q.Get());

  q.Put(31);

  EXPECT_EQ(42, q.Get());
  EXPECT_EQ(31, q.Get());
}
