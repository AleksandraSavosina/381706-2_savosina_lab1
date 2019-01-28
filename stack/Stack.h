
#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
  int size;		// ðàçìåð ñòåêà
  T* mas;			// ýëåìåíòû ñòåêà
  int top;		// âåðõ
public:
  TStack()				// êîíñòðóêòîð ïî óìîë÷àíèþ
  {
    size = 0;
    mas = 0;
    top = 0;
  }
  TStack(int _size)		// êîíñòðóêòîð ñ ïàðàìåòðîì
  {
    if (_size < 0)
      throw "negative size";

    if (_size == 0)
    {
      size = 0;
      mas = 0;
      top = 0;
    }
    else
    {
      mas = new T[_size];
      size = _size;
      top = 0;
    }
  }
  TStack(TStack &h)		// êîíñòðóêòîð êîïèðîâàíèÿ
  {
    size = h.size;
    top = h.top;
    if (size == 0)
      mas = 0;
    else
    {
      mas = new T[size];
      for (int i = 0; i < size; i++)
        mas[i] = h.mas[i];
    }
  }

  ~TStack()				// äåñòðóêòîð
  {
    delete[] mas;
  }

  void Put(T h)			// ïîëîæèòü
  {
    if (IsFull())
      throw "stack is full";
    else
    {
      mas[top] = h;
      top++;
    }
  }
  T Get()				// âçÿòü
  {
    if (IsEmpty())
      throw "stack is empty";
    else
    {
      top--;
      return mas[top];
    }
  }
  bool IsFull()			// ïðîâåðêà íà ïîëíîòó
  {
    return (top >= size);
  }
  bool IsEmpty()			// ïðîâåðêà íà ïóñòîòó
  {
    return (top == 0);
  }
};

#endif
