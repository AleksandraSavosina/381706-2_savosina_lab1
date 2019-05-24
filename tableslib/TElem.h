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
  TElem() 
  {  }

  TElem(string _key, T _data)
  {
    key = _key;
    data = _data;
  }

  ~TElem() {}

  TElem& operator = (const TElem<T>& h)
  {
    if (this != &h) {
      data = h.data;
      key = h.key;
    }

    return *this;
  }

  bool operator==(TElem& h)
  {
    return (data == h.data && key == h.key);
  }

  bool operator!=(TElem& h)
  {
    return !(data == h.data && key == h.key);
  }

  bool operator < (TElem& h)
  {
    return (key < h.key);
  }

  bool operator > (TElem& h)
  {
    return (key > h.key);
  }

  T& GetData()
  {
    return data;
  }
  void SetData(const T& _data)
  {
    data = _data;
  }
  string& GetKey()
  {
    return key;
  }
  void SetKey(const string& _key)
  {
    key = _key;
  }

  friend ostream& operator << (ostream& out, TElem& h)
  {
    out << "key: " << h.key << " . ";
    out << "data: " << h.data << endl;
    return out;
  }
};
