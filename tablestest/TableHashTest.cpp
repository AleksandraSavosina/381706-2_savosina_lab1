#include "TTableHash.h"
#include <gtest.h>
#include <string>

using namespace std;


TEST(THashTable, can_create_hashtable)
{
  ASSERT_NO_THROW(THashTable<int> table(17));
}

TEST(THashTable, can_add_element_to_hashtable)
{
  THashTable<int> table(100);
  string key("testkey");
  TElem<int> elem(key, 17);
  ASSERT_NO_THROW(table.Add(elem));
}

TEST(THashTable, can_add_element_to_full_hashtable)
{
  THashTable<int> table(3);
  string key("testkey");
  TElem<int> elem(key, 17);
  ASSERT_NO_THROW(table.Add(elem));
}

TEST(THashTable, can_add_element_to_hashtable_2)
{
  THashTable<int> table(5);
  string key("testkey");
  TElem<int> elem(key, 7);
  table.Add(elem);
  EXPECT_EQ(table.Search(key), 7);
}

TEST(THashTable, can_add_element_to_hashtable_1)
{
  THashTable<int> table(100);
  string key("testkey");
  ASSERT_NO_THROW(table.Add(key, 17));
}

TEST(THashTable, can_add_element_to_full_hashtable_1)
{
  THashTable<int> table(3);
  string key("testkey");
  ASSERT_NO_THROW(table.Add(key, 17));
}

TEST(THashTable, can_add_element_to_hashtable_4)
{
  THashTable<int> table(5);
  string key("testkey");
  table.Add(key, 10);
  EXPECT_EQ(table.Search(key), 10);
}

TEST(THashTable, can_return_count)
{
  THashTable<int> table(5);
  ASSERT_NO_THROW(table.GetCount());
}

TEST(THashTable, can_return_count_1)
{
  THashTable<int> table(5);
  EXPECT_EQ(0, table.GetCount());
}

TEST(THashTable, can_return_count_2)
{
  THashTable<int> table(5);
  string key("testkey");
  table.Add(key, 17);
  ASSERT_NO_THROW(table.GetCount());
}

TEST(THashTable, can_return_count_4)
{
  THashTable<int> table(5);
  string key("testkey");
  table.Add(key, 17);
  EXPECT_EQ(1, table.GetCount());
}

TEST(THashTable, can_delete_element_from_hashtable)
{
  THashTable<int> table(100);
  string key("testkey");
  TElem<int> elem(key, 17);
  table.Add(elem);
  EXPECT_EQ(table.Delete(key), 1);
}

TEST(THashTable, can_delete_element_from_hashtable_1)
{
  THashTable<int> table(5);
  string key("testkey");
  TElem<int> elem(key, 17);
  table.Add(elem);
  EXPECT_EQ(table.Delete(key), 1);
}

TEST(THashTable, can_add_element_to_hashtable_5)
{
  THashTable<int> table(5);
  string key("testkey1");
  string key1("testkey2");
  string key2("testkey3");
  string key3("testkey4");
  string key4("testkey5");
  table.Add(key, 10);
  table.Add(key1, 15);
  table.Add(key2, 20);
  table.Add(key3, 25);
  table.Add(key4, 30);
  EXPECT_EQ(table.Search(key2), 20);
}

TEST(THashTable, can_overcome_the_conflict_0)
{
  THashTable<int> table(5);
  string key1("testkey1");
  string key2("testkey2");
  table.Add(key1, 15);
  table.Add(key2, 20);
  ASSERT_NO_THROW(table.Search(key2));
}

TEST(THashTable, can_overcome_the_conflict_1)
{
  THashTable<int> table(5);
  string key1("testkey1");
  string key2("testkey2");
  string key3("testkey3");
  string key4("testkey4");
  table.Add(key1, 15);
  table.Add(key2, 20);
  table.Add(key3, 25);
  table.Add(key4, 30);
  ASSERT_NO_THROW(table.Search(key2));
}

TEST(THashTable, can_overcome_the_conflict_3)
{
  THashTable<int> table(5);
  string key1("testkey1");
  string key2("testkey2");
  table.Add(key1, 15);
  table.Add(key2, 20);
  EXPECT_EQ(table.Search(key2), 20);
}

TEST(THashTable, can_overcome_the_conflict_4)
{
  THashTable<int> table(5);
  string key1("testkey1");
  string key2("testkey2");
  string key3("testkey3");
  string key4("testkey4");
  table.Add(key1, 15);
  table.Add(key2, 20);
  table.Add(key3, 25);
  table.Add(key4, 30);
  EXPECT_EQ(table.Search(key3), 25);
}

TEST(THashTable, can_return_false_if_number_is_simple)
{
  THashTable<int> table(5);
  EXPECT_EQ(table.IsSimple(156), false);
}

TEST(THashTable, can_return_true_if_number_is_simple)
{
  THashTable<int> table(5);
  EXPECT_EQ(table.IsSimple(157), true);
}
