#include <gtest.h>
#include "arrlist.h"

TEST(ArrList, can_create_list_with_size)
{
	ASSERT_NO_THROW(TArrList <int> list(7));
}

TEST(ArrList, can_create_list_without_size)
{
	ASSERT_NO_THROW(TArrList <int> list());
}

TEST(ArrList, can_create_copy_of_list)
{
	TArrList <int> list(7);

	ASSERT_NO_THROW(TArrList <int> copyList(list));
}

TEST(ArrList, can_create_copy_of_empty_list)
{
	TArrList <int> list(1);
	list.PutStart(1);
	TArrList <int> copyList(list);
	ASSERT_EQ(list.GetStart(), copyList.GetStart());
}

TEST(ArrList, can_get_in_start)
{
	TArrList <int> list(2);
	list.PutStart(5);
	list.PutStart(7);
	ASSERT_EQ(7, list.GetStart());
}

TEST(ArrList, can_put_in_start)
{
	TArrList <int> L(2);
	L.PutStart(5);
	L.PutStart(7);
	ASSERT_EQ(7, L.GetStart());
}

TEST(ArrList, throws_when_create_list_with_negative_size)
{
	ASSERT_ANY_THROW(TArrList <int> L(-1));
}

TEST(ArrList, can_put_and_get_end)
{
	TArrList <int> list(2);
	list.PutEnd(5);
	list.PutEnd(7);
	ASSERT_EQ(7, list.GetEnd());
	ASSERT_EQ(5, list.GetEnd());
}

TEST(ArrList, function_isfull_works)
{
	TArrList <int> list(1);
	list.PutStart(5);
	ASSERT_TRUE(list.IsFull());
}

TEST(ArrList, can_use_empty_check_false)
{
	TArrList <int> list(1);
	list.PutStart(5);
	ASSERT_FALSE(list.IsEmpty());
}

TEST(ArrList, can_use_empty_check_true)
{
	TArrList <int> list(1);
	ASSERT_TRUE(list.IsEmpty());
}

TEST(ArrList, throws_when_put_in_full_list_in_start)
{
	TArrList <int> list(1);
	list.PutStart(1);
	ASSERT_ANY_THROW(list.PutStart(2));
}

TEST(ArrList, throws_when_put_in_full_list_in_finish)
{
	TArrList <int> list(1);
	list.PutStart(1);
	ASSERT_ANY_THROW(list.PutEnd(2));
}

TEST(ArrList, throws_when_get_in_empty_list_in_start)
{
	TArrList <int> list(1);
	ASSERT_ANY_THROW(list.GetStart());
}

TEST(ArrList, throws_when_in_empty_list_get__in_end)
{
	TArrList <int> list(1);
	ASSERT_ANY_THROW(list.GetEnd());
}

TEST(ArrList, throws_when_get_in_empty_list)
{
	TArrList <int> list(9);
	ASSERT_ANY_THROW(list.Get(3));
}

TEST(ArrList, throws_when_put_in_full_list)
{
	TArrList <int> list(3);
	list.PutEnd(1);
	list.PutEnd(1);
	list.PutEnd(1);

	ASSERT_ANY_THROW(list.Put(1, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_put)
{
	TArrList <int> list(4);
	list.PutEnd(1);
	list.PutEnd(1);
	list.PutEnd(1);

	ASSERT_ANY_THROW(list.Put(10, 6));
}

TEST(ArrList, can_get_elem)
{
	TArrList <int> L(3);
	list.PutEnd(1);
	list.PutEnd(2);
	list.PutEnd(3);

	ASSERT_EQ(list.Get(1), 2);
}

TEST(ArrList, can_put_elem)
{
	TArrList <int> list(4);
	list.PutEnd(1);
	list.PutEnd(2);
	list.PutEnd(3);
	list.Put(2, 10);

	ASSERT_EQ(list.Get(1), 2);
	ASSERT_EQ(list.Get(1), 10);
}