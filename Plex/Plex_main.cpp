
#include  <string>
#include  <iostream>
#include "TElem.h"
#include "TTableSee.h"
//#include "TTableSort.h"
//#include "TTableHash.h"
//#include "TTableTree.h"

#define TSEE
//#define TSORT
//#define THASH
//#define TTREE

using namespace std;

#ifdef TSEE

int main()
{
  //TElem<int> el();
  //THashTable<int> TabH(5);
  
  //TTable<int> table;
  int count;
  cout << "Enter count of elements in SeeTable: ";
  cin >> count;
  TTable<int> table(count);////
  TElem<int> elem;
  char str[30];

  for (int i = 1; i <= count; i++)
  {
    int data;
    cout << "Enter key " << i << ": ";
    cin >> str;
    string key(str);
    cout << "Enter data " << i << ": ";
    cin >> data;
    elem.SetData(data);
    elem.SetKey(key);
    table.Add(elem);
  }
  cout << "Your SeeTable: " << endl << table << endl;
  
  cout << "Enter count of elements in table to delete: ";
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    cout << "Write key: ";
    cin >> str;
    string key(str);
    table.Delete(key);
  }

  cout << "Your SeeTable after delete: " << endl << table;
  
  return 0;
}

#endif

#ifdef TSORT

int main()
{
  return 0;
}

#endif

#ifdef THASH

int main()
{
  return 0;
}

#endif

#ifdef TTREE

int main()
{
  return 0;
}

#endif
