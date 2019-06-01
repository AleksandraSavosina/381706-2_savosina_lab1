#pragma once
#include "TElem.h"

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
  THashTable(const int _size = 1);
  THashTable(const THashTable<T>& h);
  ~THashTable();

  int GetCount() const;
  void Add(string& key, const T& data);
  void Add(TElem<T>& elem);
  bool Del(string& key);
  T& Search(string& key);

  friend std::ostream& operator<<(const std::ostream& out, const THashTable<T>& table)
  {
    for (int i = 0; i < count; i++)
      out << table.node[i] << std::endl;
    return out;
  }
};


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
  if (size == 1){
    m = 1;
    //break;
  }
  else {
    while (size % m == 0){
      if (size == 1)
      {
        m = 1;
        break;
      }
      m++;
    }
  }
  
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
  delete[] node;
}

template <class T>
int THashTable<T>::GetCount() const
{
  return count;
}

template <class T>
void THashTable<T>::Add(string& key, const T& data)
{
  if (count == size)
    throw ("error: no place to add");
  int i = Hash(key);
  if (i > size)
    throw ("error: incorrect value");
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
    throw ("error: no place to add");
  int i = Hash(elem.GetKey());
  if (i > size)
    throw ("error: incorrect value");
  while (node[i] != qemp)
    i = (i + m) % size;
  node[i] = elem;
  count++;
}

template <class T>
bool THashTable<T>::Del(string& key)
{
  int i = Hash(key);
  while (node[i].GetKey() != key)
  {
    if (node[i] == qemp)
      return false;
    i = (i + m) % size;
  }
  node[i] = qemp;
  return true;
}

template <class T>
T& THashTable<T>::Search(string& key)
{
  int i = Hash(key);
  while (node[i].GetKey() != key)
  {
    i = (i + m) % size;
    if (node[i] == qemp)
      break;
  }
  return node[i].GetData();
}

template <class T>
int THashTable<T>::Hash(string& _key)
{
  unsigned int hash = 0;
  for (int i = 0; i < key.GetCount(); i++)
    hash = (hash >> 1) + _key[i];
  return hash;
}