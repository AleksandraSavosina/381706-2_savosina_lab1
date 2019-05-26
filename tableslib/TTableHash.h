#pragma once

#include  <string>
#include  <iostream>
#include "TElem.h"

using namespace std;

template <class T>
class THashTable
{
protected:
  static TElem<T> qemp;
  TElem<T>* node;
  int count;
  int size;
  int m;
  int Hash(string& key);
public:
  THashTable(const int _size);
  THashTable(const THashTable<T>& h);
  ~THashTable();

  int GetCount() const;
  int GetSize() const;
  void Add(string& key, const T& data);
  void Add(TElem<T>& elem);
  bool Delete(string& key);
  T& Search(string& key);
  bool IsSimple(const int num);
  void Expansion(int newsize);

  friend std::ostream& operator<<(ostream& out, const THashTable<T>& table)
  {
    for (int i = 0; i < table.GetSize(); i++)
      if (table.node[i] != qemp)
      {
        out << table.node[i] << endl;
      }
    return out;
  }
};

//--------------------------------------------ooo-------------------------------------

template <class T>
TElem<T> THashTable<T>::qemp;

template <class T>
THashTable<T>::THashTable(const int _size)
{
  if (_size <= 0)
    throw ("error: incorrect value");
  count = 0;
  size = _size;
  m = 2;
  if (size == 1) {
    m = 1;
  }
  /*else {
    while (size % m == 0) {
      if (size == 1)
      {
        m = 1;
        break;
      }
      m++;
    }*/

    node = new TElem<T>[size];
    for (int i = 0; i < size; i++)
      node[i] = qemp;
}

template <class T>
THashTable<T>::THashTable(const THashTable<T>& h)
{
  count = h.count;
  size = h.size;
  m = h.m;
  node = new TElem<T>[size];
  for (int i = 0; i < size; i++)
    node[i] = h.node[i];
}

template <class T>
THashTable<T>::~THashTable()
{
  size = 0;
  count = 0;
  delete[] node;
}

template <class T>
int THashTable<T>::GetCount() const
{
  return count;
}

template <class T>
int THashTable<T>::GetSize() const
{
  return size;
}

template <class T>
void THashTable<T>::Add(string& key, const T& data)
{
  if (count == size)
    Expansion(count * 2);
  int i = Hash(key);
  if (i > size)
    Expansion(i + 10);
  while (node[i] != qemp)
    i = (i + m) % size;
  node[i].SetKey(key);
  node[i].SetData(data);
  count++;
}

template <class T>
void THashTable<T>::Add(TElem<T>& elem)
{
  if (count == size)
    Expansion(count * 2);
  int i = Hash(elem.GetKey());
  if (i > size)
    Expansion(i + 10);
  while (node[i] != qemp)
    i = (i + m) % size;
  node[i] = elem;
  count++;
}

template <class T>
bool THashTable<T>::Delete(string& _key)
{

  for (int t = 0; t < size; t++)
  {
    if (node[t].GetKey() == _key)
    {
      node[t] = qemp;
      break;
    }
  }
  count--;
  return true;
}

template <class T>
T& THashTable<T>::Search(string& _key)
{
  int t;
  for (t = 0; t < size; t++)
  {
    if (node[t].GetKey() == _key)
      break;
    
  }

  /*int i = Hash(_key);
  while (node[i].GetKey() != _key)
  {
    i = (i + m) % size;
    if (node[i] == qemp)
      break;
  }*/
  return node[t].GetData();
}

template <class T>
bool THashTable<T>::IsSimple(const int num)
{
  for (int i = 2; i < num / 2; i++)
    if (num%i == 0)
      return false;
  return true;
}

template <class T>
int THashTable<T>::Hash(string& _key)
{
  unsigned int hash = 0;
  for (int i = 0; i < count; i++)
    hash = (hash >> 1) + _key[i];
  /*m = 2;
  while (size % m == 0)
  m++;*/
  return hash;
}

template <class T>
void THashTable<T>::Expansion(int newsize)
{
  if (newsize > size)
  {
    while (IsSimple(newsize) == 0)
      newsize++;
    TElem<T>* tmp = new TElem<T>[newsize];
    for (int i = 0; i < size; i++)
      tmp[i] = node[i];
    for (int i = size; i < newsize; i++)
      tmp[i] = qemp;
    size = newsize;
    delete[] node;
    node = tmp;

  }
  else
    throw "error";
}

