#include <gtest.h>
#include "MStack.h"
#include <iostream>


TEST(MStack, can_create_multistack_with_positive_size)
{
	ASSERT_NO_THROW(MStack<int> v(9, 3));
}

TEST(MStack, throw_when_negative_size)
{
	ASSERT_ANY_THROW(MStack<int> v(-3, 1));
}

TEST(MStack, throw_when_negative_count)
{
	ASSERT_ANY_THROW(MStack<int> v(-3, -1));
}


TEST(MStack, empty_stack_is_empty)
{
	MStack<int> stack(10, 2);

	EXPECT_EQ(1, stack.IsEmpty(0));
}




TEST(MStack, can_put_value)
{
	MStack<int> stack(10, 2);

	ASSERT_NO_THROW(stack.Put(1, 5));
}


TEST(MStack, can_get_value)
{
	MStack<int> stack(10, 2);
	stack.Put(1, 5);

	EXPECT_EQ(5, stack.Get(1));
}

TEST(MStack, can_put_multy_value)
{
	MStack<int> stack(10, 2);
	stack.Put(0, 3);
	stack.Put(0, 1);
	stack.Put(0, 4);
	stack.Put(0, 1);
	stack.Put(0, 5);
	stack.Put(1, 2);
	stack.Put(1, 7);
	stack.Put(1, 1);
	stack.Put(1, 8);
	stack.Put(1, 2);
	EXPECT_EQ(5, stack.Get(0));
}

TEST(MStack, throw_when_get_from_empty_stack)
{
	const int Size = 5;
	MStack<int> stack(Size, 2);
	ASSERT_ANY_THROW(stack.Get(0));
}