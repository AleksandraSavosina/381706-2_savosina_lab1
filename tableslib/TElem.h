#pragma once
#include <string>
#include  <iostream>

using namespace std;

template <class T>
class TElem
{
protected:
  string key;
  T data;

public:
  TElem() { data = NULL; }

  TElem(string _key = " ", T _data = 0)
  {
    key = _key;
    data = _data;
  }

  ~TElem() {}

  TElem& operator = (const TElem<T>& h)
  {
    if (this != &h){
      data = h.data;
      key = h.key;
    }
  
    return *this;
  }

  bool operator==(TElem& h)
  {  return (data == h.data && key == h.key); }

  bool operator!=(TElem& h) 
  {  return !(data == h.data && key == h.key); }

  bool operator < (TElem& h)
  {  return (key < h.key); }

  bool operator > (TElem& h)
  {  return (key > h.key); }

  T& GetData() 
  {  return data; }
  void SetData(const T& _data) 
  {  data = _data; }
  string& GetKey() 
  {  return key; }
  void SetKey(const string& _key) 
  {  key = _key; }

  friend ostream& operator << (ostream& out, TElem& h)
  {
    out << h.key << "/t";
    out << h.data << endl;
    return out;
  }
};

//--------------------------------------------------------------------
template <class T>
class TTreeElem
{
protected:
  TElem *left, *right, *parent;
public:
  TTreeElem() {}
  ~TTreeElem() {}

};