
#include  <string>
#include  <iostream>
#include "TElem.h"
#include "TTableHash.h"

using namespace std;

int main()
{
  int count;
  cout << "Write count of elements in table: ";
  cin >> count;
  THashTable<int> table(count);
  TElem<int> elem;
  char str[100];
  for (int i = 0; i < count; i++)
  {
    int data;
    cout << "Write key " << i + 1 << ": ";
    cin >> str;
    cout << "Write data " << i + 1 << ": ";
    cin >> data;
    string curr_key(str);
    elem.SetData(data);
    elem.SetKey(curr_key);
    table.Add(curr_key, data);
  }
  cout << "Your HashTable: " << endl << table;
  cout << "Write count of elements in table that you want to delete: ";
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    cout << "Write key: ";
    cin >> str;
    string curr_key(str);
    table.Delete(curr_key);
  }
  cout << "Your HashTable after delete: " << endl << table;
  
  return 0;
}
