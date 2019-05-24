#pragma once

#include  <string>
#include  <iostream>
#include "TElem.h"

using namespace std;

template <class T>
class TTable
{
protected:
  static TElem<T> qemp;
  TElem<T>* node;
  int size;
  int count;
public:
  TTable(const int _size);
  TTable(TTable<T> & h);
  ~TTable();

  bool Add(const TElem<T> & h);
  bool Add(T& _data);
  int GetCount() const { return count; }

  void Expansion(int newSize);	// increase table size

  void Delete(TElem<T> & h);
  bool Delete(const string& _key);
  TElem<T>& Search(string _k);
  int& operator [](string _key);

  friend ostream& operator << (ostream& out, TTable<T>& A)
  {
    for (int i = 0; i < A.count; i++)
      out << A.node[i] << endl;
    return out;
  }
};

//--------------------------------------------ooo-------------------------------------

template <class T>
TElem<T> TTable<T>::qemp;

template <class T>
TTable<T>::TTable(const int _size)
{
  if (_size < 1)
    throw ("error: incorrect value");
  size = _size;
  node = new TElem<T>[_size];
  count = 0;
  for (int i = 0; i < size; i++) {
    node[i] = qemp;
  }
}

template <class T>
TTable<T>::TTable(TTable<T> & h)
{
  size = h.size;
  count = h.count;
  node = new TElem<T>[size];

  for (int i = 0; i < size; i++) {
    node[i] = h.node[i];
  }
}

template <class T>
TTable<T>::~TTable()
{
  count = 0;
  size = 0;
  delete[] node;
}

template <class T>
bool TTable<T>::Add(const TElem<T> & h)
{
  if (size == count)
    Expansion(count * 2);
  node[count] = h;
  count++;
  return true;
}

template <class T>
bool TTable<T>::Add(T& _data)
{
  if (size == count)
    Expansion(count * 2);
  string tmp("NewKey");
  node[count].SetData(_data);

  if (count == 0)
    node[count].SetData(_data);
  else
  {
    char pmt = node[count - 1].GetKey();
    string phelp;

    int con = strlen(pmt);
    char* str = new char[con + 1];
    for (int i = 0; i < con; i++)
      str[i] = pmt[i];
    str[con] = '\0';

    tmp = phelp;
    node[count].SetKey(tmp);
  }

  count++;
  return true;
}

template <class T>
void TTable<T>::Expansion(int newSize)	// increase table size
{
  if (size < newSize) {
    TElem<T>* newArr;
    newArr = new TElem<T>[newSize];

    for (int i = 0; i < count; i++)
      newArr[i] = node[i];
    for (int i = count; i < newSize; i++)
      newArr[i] = qemp;

    size = newSize;
    //TElem* dnode = node;
    delete[] node;
    node = newArr;
    //delete[] dnode;
  }
  else
    throw ("error: table can't be increased");
}

template <class T>
void TTable<T>::Delete(TElem<T> & h)
{
  if (count == 0)
    throw ("error: nothing to delete");

  for (int i = 0; i < count; i++) {
    if (node[i].GetKey() == h.GetKey())
      for (int j = 0; j < count - 1; j++)
        node[j] = node[j + 1];
    count--;
  }
}

template <class T>
bool TTable<T>::Delete(const string& _key)
{
  if (count == 0)
    return false;
  bool flag = false;
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == _key)
    {
      for (int j = i; j < count - 1; j++)
        node[j] = node[j + 1];
      flag = true;
      break;
    }
  if (flag == true)
    count--;
  return flag;
}

template <class T>
TElem<T>& TTable<T>::Search(string _k)
{
  for (int i = 0; i < count; i++)
    if (node[i].GetKey() == _k)
      return node[i];
  return qemp;
}

template <class T>
int& TTable<T>::operator [](string _key)
{
  return Search(_key).GetData();
}
