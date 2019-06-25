#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>

using namespace std;

template <class T>

class TStack
{
protected:
  int size; // размер стека
  T* mas;   // память стека 
  int top;  // верхушка стека
public:
  TStack() // конструктор
  {
    size = 0;
    mas = 0;
    top = 0;
  }
  TStack(int _size) // конструктор
  {
    if (_size < 0)
      throw "negative size";

    if (_size == 0){
      size = 0;
      mas = 0;
      top = 0;
    }
    else{
      mas = new T[_size];
      size = _size;
      top = 0;
    }
  }

  TStack(TStack &h) // копирование
  {
    size = h.size;
    top = h.top;
    if (size == 0)
      mas = 0;

    else{
      mas = new T[size];
      for (int i = 0; i < size; i++)
        mas[i] = h.mas[i];
    }
  }

  ~TStack() // деструктор
  {
    delete[] mas;
  }

  void Put(T h) // положить
  {
    if (IsFull())
      throw "stack is full";

    else{
      mas[top] = h;
      top++;
    }
  }

  T Get() // достать с удалением
  {
    if (IsEmpty())
      throw "stack is empty";
    else{
      --top;
      return mas[top];
    }
  }

  T Top() // посмотреть на последний элемент
  {
    if (IsEmpty())
      throw "stack is empty";
    else{
      return mas[top - 1];
    }
  }

  bool IsFull() // полнота
  {
    return (top >= size); 
  }

  bool IsEmpty() // пустота
  {
    return (top == 0);
  }

  void Print() // печать
  {
    cout << "Stack: " << endl;
    for (int i = 0; i < top; i++){
      cout << mas[i] << " / ";
    }
  }
};

#endif
