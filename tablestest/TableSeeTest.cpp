#include "TTableSort.h"
#include <gtest.h>
#include <string>

using namespace std;

TEST(sorttables, can_create_sort_table)
{
  ASSERT_NO_THROW(TSortTable<int> table);
}

TEST(sorttables, can_creaate_sort_table_with_size)
{
  ASSERT_NO_THROW(TSortTable<int> table(10));
}

TEST(sorttables, can_add_element_to_sort_table)
{
  TSortTable<int> table(10);
  string key("key");
  TElem<int> elem(key, 10);
  table.Add(elem);
}

TEST(sorttables, can_add_element_to_sort_table_1)
{
  TSortTable<int> table(5);
  string key("key");
  TElem<int> elem(key, 10);
  EXPECT_EQ(table.Add(elem), 1);
}

TEST(sorttables, can_add_element_to_full_sorttable_0)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem3);
  table.Add(elem1);
  table.Add(elem2);
  ASSERT_NO_THROW(table.Add(elem4));
}

TEST(sorttables, can_add_element_to_full_sorttable_1)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem3);
  table.Add(elem1);
  table.Add(elem2);
  EXPECT_EQ(table.Add(elem4), 1);
}

TEST(sorttables, can_add_element_to_sorttable)
{
  TSortTable<int> table(5);
  string key("key");
  TElem<int> elem(key, 10);
  table.Add(elem);
  EXPECT_EQ(table[key], 10);
}

TEST(sorttables, can_search_element_to_sorttable_0)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem3);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem4);
  ASSERT_NO_THROW(table.Search(key3));
}

TEST(sorttables, can_search_element_to_sorttable_1)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  ASSERT_NO_THROW(table.Search(key4));
}

TEST(sorttables, can_search_element_to_sorttable)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  EXPECT_EQ(table.Search(key3) == elem3, 1);
}

TEST(sorttables, cad_delete_element_in_sorttable_0)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  ASSERT_NO_THROW(table.Delete(elem3));
}
//
TEST(sorttables, cad_delete_element_in_sorttable_1)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  ASSERT_NO_THROW(table.Delete(key3));
}

TEST(sorttables, cad_throw_if_count_of_elements_in_sort_table_is_zero_0)
{
  TSortTable<int> table(3);
  string key3("key3");
  TElem<int> elem3(key3, 10);
  EXPECT_EQ(table.Delete(elem3), 0);
}

TEST(sorttables, cad_throw_if_count_of_elements_in_sort_table_is_zero_1)
{
  TSortTable<int> table(3);
  string key3("key3");
  EXPECT_EQ(table.Delete(key3), 0);
}

TEST(sorttables, cad_delete_element_in_sort_table_2)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  EXPECT_EQ(table.Delete(elem3), 1);
}

TEST(sorttables, cad_delete_element_in_sort_table_3)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 10);
  TElem<int> elem3(key3, 10);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  EXPECT_EQ(table.Delete(key3), 1);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_0)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  table.Delete(elem2);
  EXPECT_EQ(table[key3], 20);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_1)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  table.Delete(key2);
  EXPECT_EQ(table[key3], 20);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_2)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  table.Delete(elem2);
  EXPECT_EQ(table[key2] == 0, 1);
}

TEST(sorttables, cad_delete_element_in_sort_table_correct_3)
{
  TSortTable<int> table(3);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  table.Add(elem1);
  table.Add(elem2);
  table.Add(elem3);
  table.Add(elem4);
  table.Delete(key2);
  EXPECT_EQ(table[key2] == 0, 1);
}

TEST(sorttables, can_sort_seetable_by_insert_sort_0)
{
  TTable<int> table(5);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  string key5("key5");
  string key6("key6");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  TElem<int> elem5(key5, 25);
  TElem<int> elem6(key6, 1);
  table.Add(elem4);
  table.Add(elem2);
  table.Add(elem1);
  table.Add(elem3);
  table.Add(elem6);
  table.Add(elem5);
  ASSERT_NO_THROW(TSortTable<int>::InsertSort(table));
}

TEST(sorttables, can_sort_seetable_by_insert_sort_correct_0)
{
  TTable<int> table(5);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  string key5("key5");
  string key6("key6");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  TElem<int> elem5(key5, 25);
  TElem<int> elem6(key6, 1);
  table.Add(elem4);
  table.Add(elem2);
  table.Add(elem1);
  table.Add(elem3);
  table.Add(elem6);
  table.Add(elem5);
  TSortTable<int>::InsertSort(table);
  EXPECT_EQ(table.Search(key6) == elem6, 1);
}

TEST(sorttables, can_sort_seetable_by_insert_sort_correct)
{
  TTable<int> table(5);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  string key5("key5");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  TElem<int> elem5(key5, 25);
  table.Add(elem4);
  table.Add(elem2);
  table.Add(elem1);
  table.Add(elem3);
  table.Add(elem5);
  TSortTable<int>::InsertSort(table);
  EXPECT_EQ(table.Search(key5) == elem5, 1);
}



TEST(sorttables, can_sort_seetable_by_merge_sort_correct_0)
{
  TTable<int> table(5);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  string key5("key5");
  string key6("key6");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  TElem<int> elem5(key5, 25);
  TElem<int> elem6(key6, 1);
  table.Add(elem4);
  table.Add(elem2);
  table.Add(elem1);
  table.Add(elem3);
  table.Add(elem6);
  table.Add(elem5);
  TSortTable<int>::MergeSort(table, table.GetCount(), 0);
  EXPECT_EQ(table.Search(key6) == elem6, 1);
}

TEST(sorttables, can_sort_seetable_by_merge_sort_correct_1)
{
  TTable<int> table(5);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  string key5("key5");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  TElem<int> elem5(key5, 25);
  table.Add(elem4);
  table.Add(elem2);
  table.Add(elem1);
  table.Add(elem3);
  table.Add(elem5);
  TSortTable<int>::MergeSort(table, table.GetCount(), 0);
  EXPECT_EQ(table.Search(key5) == elem5, 1);
}

TEST(sorttables, can_sort_seetable_by_quick_sort_0)
{
  TTable<int> table(5);
  string key1("key1");
  string key2("key2");
  string key3("key3");
  string key4("key4");
  string key5("key5");
  string key6("key6");
  TElem<int> elem1(key1, 10);
  TElem<int> elem2(key2, 15);
  TElem<int> elem3(key3, 20);
  TElem<int> elem4(key4, 5);
  TElem<int> elem5(key5, 25);
  TElem<int> elem6(key6, 1);
  table.Add(elem4);
  table.Add(elem2);
  table.Add(elem1);
  table.Add(elem3);
  table.Add(elem6);
  table.Add(elem5);
  ASSERT_NO_THROW(TSortTable<int>::QuickSort(table, 0, table.GetCount() - 1));
}
