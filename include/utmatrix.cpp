#include "stdafx.h"
#include "Stack.h"


//
//template <class T>
//TStack<T>::TStack()				// конструктор по умолчанию
//{
//	size = 0;
//	mas = 0;
//	top = 0;
//}
//
//template <class T>
//TStack<T>::TStack(int _size)	 // конструктор с параметром
//{
//	if (_size < 0)
//		throw "negative size";
//
//	if (_size == 0) 
//	{
//		size = 0;
//		mas = 0;
//		top = 0;
//	}
//	else 
//	{
//		mas = new T[_size];
//		size = _size;
//		top = 0;
//	}
//}
//
//template <class T>				// деструктор
//TStack<T>::~TStack()
//{
//	delete[] mas;
//}
//
//template <class T>				// конструктор копирования
//TStack<T> :: TStack(TStack &h)
//{
//	size = h.size;
//	top = h.top;
//	if (size == 0)
//		mas = 0;
//	else 
//	{
//		mas = new T[size];
//		for (int i = 0; i < size; i++)
//			mas[i] = h.mas[i];
//	}
//}
//
//template <class T>				// проверка на пустоту
//bool TStack<T>::IsEmpty() 
//{
//	if (top == 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//template <class T>				// проверка на полноту
//bool TStack<T>::IsFull() 
//{
//	return !IsEmpty();
//}
//
//template <class T>				// положим что-нибудь
//void TStack<T>::Put(T h) 
//{
//	if (IsFull())
//		throw "stack is full";
//	else 
//	{
//		mas[top] = h;
//		top++;
//	}
//}
//
//template <class T>				// возьмём что-нибудь
//T TStack<T>::Get() 
//{
//	if (IsEmpty())
//		throw "stack is empty";
//	else 
//	{
//		top--;
//		return mas[top];
//	}
//}
//
