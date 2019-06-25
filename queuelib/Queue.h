#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>

using namespace std; 

template <class T>

class TQueue
{
protected:
  int size; // размер стека
  T* mas;   // элементы стека
  int top;  // верх
  int start; // начало очереди
  int count;  // кол-во эл-тов
public:
  TQueue() // конструктор по умолчанию
  {
    size = 0;
    mas = 0;
    top = 0;
    start = 0;
    count = 0;
  }

  TQueue(int _size) // конструктор с параметром
  {
    if (_size < 0)
      throw "negative size";
    mas = new T[_size];
    size = _size;
    top = 0;
    start = 0;
    count = 0;
  }

  TQueue(TQueue &h) // конструктор копирования
  {
    size = h.size;
    start = h.start;
    count = h.count;
  }

  void Put(T h) // положить в конец очереди
  {
    if (IsFull())
      throw "error: queue is full";
    else{
      mas[start] = h;
      start = (start + 1) % size;
      count++;
    }
  }

  T Get() // взять первый элемент
  {
    if (IsEmpty())
      throw "error: queue is empty";
    else{
      T tmp = mas[top];
      top = (top + 1) % size;
      count--;
      return tmp;
    }
  }

  bool IsFull() // полнота
  {
    return (count == size);
  }

  bool IsEmpty() // пустота
  {
    return (count == 0);
  }

  void Print() // печать
  {
    int hop = 0;
    cout << "Queue: " << endl;
    for (int i = start; i < size; i++) {
      cout << mas[i] << " / ";
      hop++;
    }
    for (int i = 0; i < count - hop; i++){
      cout << mas[i] << " / ";
    }
  }
};

#endif
