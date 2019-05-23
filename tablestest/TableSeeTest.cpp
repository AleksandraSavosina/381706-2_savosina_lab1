#include "TTableSee.h"
#include <gtest.h>
#include <string>

using namespace std;

TEST(TTable, can_create_table_with_size)
{
  ASSERT_NO_THROW(TTable<int> table(17));
}

TEST(TTable, can_add_element_in_table)
{
  TTable<int> table(7);
  string key("key");
  TElem<int> elem(key, 17);
  ASSERT_NO_THROW(table.Add(elem));
}

TEST(TTable, can_add_element_in_table__check_with_bool)
{
  TTable<int> table(7);
  string key("key");
  TElem<int> elem(key, 17);
  EXPECT_EQ(table.Add(elem), 1);
}

TEST(TTable, can_add_element_in_full_table)
{
  TTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 17);
  TElem<int> elem2(key2, 7);
  TElem<int> elem3(key3, 1);
  TElem<int> elem4(key4, 3);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  ASSERT_NO_THROW(table.Add(elem4));
}

TEST(TTable, can_add_element_in_full_table_check_bool)
{
  TTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 17);
  TElem<int> elem2(key2, 7);
  TElem<int> elem3(key3, 1);
  TElem<int> elem4(key4, 3);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  EXPECT_EQ(table.Add(elem4), 1);
}

TEST(TTable, can_add_element_check_bool)
{
  TTable<int> table(7);
  string key("key");
  TElem<int> elem(key, 17);
  table.Add(elem);
  EXPECT_EQ(table[key], 17);
}

TEST(TTable, can_search_element)
{
  TTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 17);
  TElem<int> elem2(key2, 7);
  TElem<int> elem3(key3, 1);
  TElem<int> elem4(key4, 3);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  ASSERT_NO_THROW(table.Search(key3));
}

TEST(TTable, can_search_element)
{
  TTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 17);
  TElem<int> elem2(key2, 7);
  TElem<int> elem3(key3, 1);
  TElem<int> elem4(key4, 3);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  ASSERT_NO_THROW(table.Search(key4));
}

TEST(TTable, can_add_int_element)
{
  TTable<int> table(5);
  int n = 17;
  ASSERT_NO_THROW(table.Add(n));
}

TEST(TTable, can_delete_element)
{
  TTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 17);
  TElem<int> elem2(key2, 7);
  TElem<int> elem3(key3, 1);
  TElem<int> elem4(key4, 3);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  ASSERT_NO_THROW(table.Delete(elem3));
}

TEST(TTable, cad_throw_in_case_of_null_size)
{
  TTable<int> table(3);
  string key3("key3");
  EXPECT_EQ(table.Delete(key3), 0);
}

TEST(TTable, cad_delete_elemen_with_key)
{
  TTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 17);
  TElem<int> elem2(key2, 7);
  TElem<int> elem3(key3, 1);
  TElem<int> elem4(key4, 3);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  EXPECT_EQ(table.Delete(key3), 1);
}
