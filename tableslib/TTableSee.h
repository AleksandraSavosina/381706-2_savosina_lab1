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
  TTable(const int _size)
  {
    if (_size < 1) 
      throw ("error: incorrect value");
    size = _size;
    node = new TElem<T>[size];
    count = 0;
    for (int i = 0; i < size; i++){
      node[i] = qemp;
    }
  }

  TTable(TTable<T> & h)
  {
    size = h.size;
    count = h.count;
    node = new TElem<T>[size];

    for (int i = 0; i < size; i++){
      node[i] = h.node[i];
    }
  }

  ~TTable()
  {
    count = 0; 
    size = 0;
    delete[] node;
  }

  bool Add(const TElem<T> & h)
  {
    if (size == count) 
      Expansion(count * 2);
    node[count] = h;
    count++;
    return true;
  }

  bool Add(T& _data)
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
      string phelp(&ptm);
      tmp = phelp;
      node[count].SetKey(tmp);
    }

    count++;
    return true;
  }

  int GetCount() const
  {
    return count;
  }

  void Expansion(int newSize)	// increase table size
  {
    if (size < newSize) {
      TElem<T>* newArr;
      newArr = new TElem<T>[newSize];

      for (int i = 0; i < count; i++)
        newArr[i] = node[i];
      for (int i = 0; i < newSize; i++)
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

  void Delete(TElem<T> & h)
  {
    if (count == 0) 
      throw ("error: nothing to delete");

    for (int i = 0; i < count; i++){
      if (node[i].key == h.key)
        for (int j = 0; j < count - 1; j++)
          node[j] = node[j + 1];
      count--;
    }
  }

  bool Delete(const string& _key)
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

  TElem<T>& Search(string _k)
  {
    for (int i = 0; i < count; i++)
      if (node[i].key == _k)
        return node[i];
    return qemp;
  }

  int& operator [](string _key)
  {
    TElem<T>& res = Search(_key);	 // êëàä¸ì çíà÷åíèå , res - ññûëêà
    if (res == qemp){    // òî íà ñàìîì äåëå íå íàøëè
      TElem<T> n;
      n.key = _key;
      n.data = 0;
      Add(n);
      return node[count - 1].data;
    }
    return res.data;
  }

  friend ostream& operator << (ostream& out, TTable<T>& A)
  {
    for (int i = 0; i < A.count; i++)
      out << A.node[i] << endl;
    return out;
  }
};


template <class T>
TElem<T> TTable<T>::qemp;
