#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>

using namespace std;

template <class T>

class TStack
{
protected:
	int size; // размер стека
	T* mas; // элементы стека
	int top; // верх
public:
	TStack() // конструктор по умолчанию
	{
		size = 0;
		mas = 0;
		top = 0;
	}
	TStack(int _size) // конструктор с параметром
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

	TStack(TStack &h) // конструктор копирования
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

	~TStack() // деструктор
	{
		delete[] mas;
	}

	void Put(T h) // положить
	{
		if (IsFull())
			throw "stack is full";

		else
		{
			mas[top] = h;
			top++;
		}
	}

	T Get() // взять
	{

		if (IsEmpty())
			throw "stack is empty";
		else
		{
			--top;
			return mas[top];
		}

	}

	bool IsFull() // проверка на полноту
	{
		return (top >= size);
	}

	bool IsEmpty() // проверка на пустоту
	{
		return (top == 0);
	}

};

#endif