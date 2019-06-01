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
  
  int size;
  int count;
public:
  TElem<T>* nod;
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
      out << A.nod[i] << endl;
    return out;
  }
};

template <class T>
TElem<T> TTable<T>::qemp;

template <class T>
TTable<T>::TTable(const int _size)
{
  if (_size < 1)
    throw ("error: incorrect value");
  size = _size;
  nod = new TElem<T>[_size];
  count = 0;
  for (int i = 0; i < size; i++) {
    nod[i] = qemp;
  }
}

template <class T>
TTable<T>::TTable(TTable<T> & h)
{
  size = h.size;
  count = h.count;
  nod = new TElem<T>[size];

  for (int i = 0; i < size; i++) {
    nod[i] = h.nod[i];
  }
}

template <class T>
TTable<T>::~TTable()
{
  count = 0;
  size = 0;
  delete[] nod;
}

template <class T>
bool TTable<T>::Add(const TElem<T> & h)
{
  if (size == count)
    Expansion(count * 2);
  nod[count] = h;
  count++;
  return true;
}

//template <class T>
//bool TTable<T>::Add(T& _data)
//{
//  if (size == count)
//    Expansion(count * 2);
//  string tmp("NewKey");
//  nod[count].SetData(_data);
//  if (count == 0)
//    nod[count].SetData(_data);
//  else
//  {
//    char pmt = nod[count - 1].GetKey();
//    string phelp;
//    int con = strlen(pmt);
//    char* str = new char[con + 1];
//    for (int i = 0; i < con; i++)
//      str[i] = pmt[i];
//    str[con] = '\0';
//    tmp = phelp;
//    nod[count].SetKey(tmp);
//  }
//  count++;
//  return true;
//}

template <class T>
void TTable<T>::Expansion(int newSize)	// increase table size
{
  if (size < newSize) {
    TElem<T>* newArr;
    newArr = new TElem<T>[newSize];

    for (int i = 0; i < count; i++)
      newArr[i] = nod[i];
    for (int i = count; i < newSize; i++)
      newArr[i] = qemp;

    size = newSize;
    delete[] nod;
    nod = newArr;
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
    if (nod[i].GetKey() == h.GetKey())
      for (int j = 0; j < count - 1; j++)
        nod[j] = nod[j + 1];
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
    if (nod[i].GetKey() == _key)
    {
      for (int j = i; j < count - 1; j++)
        nod[j] = nod[j + 1];
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
    if (nod[i].GetKey() == _k)
      return nod[i];
  return qemp;
}

template <class T>
int& TTable<T>::operator [](string _key)
{
  return Search(_key).GetData();
}

//-------------------------------------ooo----------------------------------------
//-------------------------------------ooo----------------------------------------
//-------------------------------------ooo----------------------------------------
//-------------------------------------ooo----------------------------------------
//-------------------------------------ooo----------------------------------------
//-------------------------------------ooo----------------------------------------
//-------------------------------------ooo----------------------------------------


template <class T>
class TSortTable
{
protected:
  static TElem<T> qempt;
  TElem<T>* node;
  int count;
  int size;
public:
  TSortTable(const int _size = 1);
  TSortTable(const TSortTable<T>& table);
  //TSortTable(const TTable<T>& table, const int num);
  ~TSortTable();

  int GetCount() const;
  bool Add(TElem<T>& elem);
  string& Add(const T& data);
  bool Delete(TElem<T>& elem);
  bool Delete(const string& key);
  TElem<T>& Search(const string& key) const;
  void Expansion(const int newsize);
  T& operator[](const string& key) const;
  
  friend std::ostream& operator<<(std::ostream& out, const TSortTable<T>& table)
  {
    for (int i = 0; i < table.GetCount(); i++)
      out << table.node[i] << endl;
    return out;
  }
  static void InsertSort(TTable<T>& seetable);
  static void MergeSort(TTable<T>& seetable, const int n, const int start);
  static void QuickSort(TTable<T>& seetable, const int low, const int high);
protected:
  
};

//--------------------------------------------ooo-------------------------------------

template <class T>
TElem<T> TSortTable<T>::qempt;

template <class T>
TSortTable<T>::TSortTable(const int _size)
{
  if (_size <= 0)
    throw 2;
  size = _size;
  count = 0;
  node = new TElem<T>[size];
  for (int i = 0; i < size; i++)
    node[i] = qempt;
}

/*
template <class T>
TSortTable<T>::TSortTable(const TSortTable<T>& table)
{
  size = table.size;
  count = table.count;
  node = new TElem<T>[size];
  for (int i = 0; i < size; i++)
    node[i] = table.node[i];
}
*/
template <class T>
TSortTable<T>::TSortTable(const TTable<T>& table)
{
  size = table.size;
  count = table.count;
  TTable<T> copy_t(table);
  
  TSortTable<T>::InsertSort(copy_t);
 
  node = new TElem<T>[size];
  for (int i = 0; i < count; i++)
    node[i] = copy_t.node[i];
}

template <class T>
TSortTable<T>::~TSortTable()
{
  count = 0;
  size = 0;
  delete[] node;
}

template <class T>
int TSortTable<T>::GetCount() const
{
  return count;
}

template <class T>
bool TSortTable<T>::Add(TElem<T>& elem)
{
  bool flag = false;
  if (count == 0)
  {
    node[count] = elem;
    count++;
    return true;
  }
  if (count == size)
    Expansion(count * 2);
  TElem<T> tmp;
  for (int i = 0; i <= count; i++)
  {
    if (node[i].GetKey() < elem.GetKey() && i != count)
      continue;
    else if (node[i].GetKey() > elem.GetKey() && flag == false)
    {
      flag = true;
      tmp = node[i];
      node[i] = elem;
      continue;
    }
    else if (flag == true)
    {
      TElem<T> temp = node[i];
      node[i] = tmp;
      tmp = temp;
    }
    else if (i == count && flag == false)
    {
      node[count] = elem;
      flag = true;
    }
  }
  count++;
  return flag;
}
////
//template <class T>
//string& TSortTable<T>::Add(const T& data)
//{
//  if (size == count)
//    Expansion(count * 2);
//  node[count].SetData(data);
//  string tmp("First_Key");
//  if (count == 0)
//  {
//    node[count].SetKey(tmp);
//    count++;
//    return node[count - 1].GetKey();
//  }
//  else
//  {
//    string tmp1(&(node[count - 1].GetKey().GetArrChar()[0]));
//    tmp = tmp1;
//    node[count].SetKey(tmp);
//    TElem<T> temp = node[count - 1];
//    node[count - 1] = node[count];
//    node[count] = temp;
//  }
//  count++;
//  return node[count - 2].GetKey();
//}

template <class T>
bool TSortTable<T>::Delete(TElem<T>& elem)
{
  int left = 0;
  int right = count;
  int current = count / 2;
  bool flag = false;
  while (right - left >= 1)
    if (node[current].GetKey() < elem.GetKey())
    {
      left = current;
      current = (right + left) / 2;
    }
    else if (node[current].GetKey() > elem.GetKey())
    {
      right = current;
      current = (right - left) / 2;
    }
    else if (node[current].GetKey() == elem.GetKey())
    {
      for (int i = current; i < count - 1; i++)
        node[i] = node[i + 1];
      count--;
      flag = true;
      break;
    }
  return flag;
}

template <class T>
bool TSortTable<T>::Delete(const string& key)
{
  int left = 0;
  int right = count;
  int current = count / 2;
  bool flag = false;
  while (right - left >= 1)
    if (node[current].GetKey() < key)
    {
      left = current;
      current = (right + left) / 2;
    }
    else if (node[current].GetKey() > key)
    {
      right = current;
      current = (right - left) / 2;
    }
    else if (node[current].GetKey() == key)
    {
      for (int i = current; i < count - 1; i++)
        node[i] = node[i + 1];
      count--;
      flag = true;
      break;
    }
  return flag;
}

template <class T>
TElem<T>& TSortTable<T>::Search(const string& key) const
{
  int left = 0;
  int right = count;
  int current = count / 2;
  int tmp = count / 2;
  while (right - left >= 1)
  {
    if (node[current].GetKey() < key)
    {
      left = current;
      current = (right + left) / 2;
    }
    else if (node[current].GetKey() > key)
    {
      right = current;
      current = (right - left) / 2;
    }
    else if (node[current].GetKey() == key)
      return node[current];
    if (right - left == 1)
      break;
  }
  return qempt;
}

template <class T>
T& TSortTable<T>::operator[](const string& key) const
{
  return Search(key).GetData();
}

template <class T>
void TSortTable<T>::Expansion(const int newsize)
{
  if (newsize > size)
  {
    TElem<T>* tmp = new TElem<T>[newsize];
    for (int i = 0; i < count; i++)
      tmp[i] = node[i];
    for (int i = count; i < newsize; i++)
      tmp[i] = qempt;
    size = newsize;
    delete[] node;
    node = tmp;
  }
  else
    throw 3;
}

template <class T>
void TSortTable<T>::InsertSort(TTable<T>& seetable)
{
  for (int i = 1; i < seetable.GetCount(); i++)
  {
    TElem<T> temp = seetable.nod[i];
    int j = i;
    while (j > 0 && seetable.nod[j - 1].GetKey() > temp.GetKey())
    {
      seetable.nod[j] = seetable.nod[j - 1];
      j--;
      //compare_cout++;
    }
    seetable.nod[j] = temp;
  }
  //cout << compare_cout << endl;
  //compare_cout = 0;
}

template <class T>
void TSortTable<T>::MergeSort(TTable<T>& seetable, const int n, const int start)
{
  if (n > 1)
  {
    const int left_size = n / 2;
    const int right_size = n - left_size;
    const int left_start = right_size - left_size + start - (n % 2);
    const int right_start = left_size + start;
    
    MergeSort(seetable, left_size, left_start);
    
    MergeSort(seetable, right_size, right_start);
      
    int	lid = 0, rid = left_size, xid = 0;
    
    TElem<T>* tmp = new TElem<T>[n];
    while (lid < left_size || rid < n)
    {
      //compare_cout++;
      if (seetable.nod[lid + start].GetKey() < seetable.nod[rid + start].GetKey())
      {
        tmp[xid] = seetable.nod[lid + start];
        lid++;
        xid++;
      }
      else
      {
        tmp[xid] = seetable.nod[rid + start];
        xid++;
        rid++;
      }
      if (lid == left_size)
      {
        for (int i = rid; i < n; i++)
        {
          tmp[xid] = seetable.nod[i + start];
          xid++;
        }
        break;
      }
      if (rid == n)
      {
        for (int i = lid; i < left_size; i++)
        {
          tmp[xid] = seetable.nod[i + start];
          xid++;
        }
        break;
      }
    }
    for (int i = 0; i < n; i++)
      seetable.nod[i + start] = tmp[i];
    delete[] tmp;
  }
}

template <class T>
void TSortTable<T>::QuickSort(TTable<T>& seetable, const int low, const int high)
{
  int i = low, j = high;
  TElem<T> d;
  TElem<T> m = seetable.nod[(low + high) / 2];
  while (i <= j)
  {
    for (; seetable.nod[i].GetKey() < m.GetKey(); i++);
    for (; seetable.nod[j].GetKey() > m.GetKey(); j--);
    if (i <= j)
    {
      d = seetable.nod[i];
      seetable.nod[i++] = seetable.nod[j];
      seetable.nod[j--] = d;
    }
    //compare_cout++;
  }
  if (low < j)
    QuickSort(seetable, low, j);
  if (i < high)
    QuickSort(seetable, i, high);
}
