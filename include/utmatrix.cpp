#include "utmatrix.h"

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if (s < 0 || s > MAX_VECTOR_SIZE)
		throw "error";

	if (si < 0)
		throw "error";
	

	Size = s;
	StartIndex = si;

	pVector = new ValType[s];

	for (int i = 0; i < Size; i++)
		pVector[i] = (ValType)0;

} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;

	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ - по индексу элемента достать значение (индексация другая)
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos < StartIndex || pos >= StartIndex + Size)
		throw "net";

	return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (Size != v.Size)
		return false;
	if (StartIndex != v.StartIndex)
		return false;
	for (int i = 0; i < Size; i++)
	{
		if (pVector[i] != v.pVector[i])
			return false;
	}
	return true;

} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (Size != v.Size)
	{
		delete[] pVector;
		pVector = new ValType[v.Size];
		Size = v.Size;
	}

	StartIndex = v.StartIndex;
	
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}

	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector<ValType> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = tmp.pVector[i] + val;
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector<ValType> tmp(*this);
	return tmp + (-val);

} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector<ValType> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = tmp.pVector[i] * val;
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size != v.Size)
		throw "net";

	TVector<ValType> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = tmp.pVector[i] + v.pVector[i];
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size != v.Size)
		throw "net";

	TVector<ValType> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = tmp.pVector[i] - v.pVector[i];
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if (Size != v.Size)
		throw "net";

	ValType sum = (ValType)0;
	for (int i = 0; i < Size; i++)
	{
		sum += pVector[i] * v.pVector[i];

	}

	return sum;
} 

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
	if ( s > MAX_MATRIX_SIZE)
		throw "error";

	for (int i = 0; i < s; i++)
	{
		TVector<ValType> tmp(s-i,i);
		pVector[i] = tmp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	if (Size != mt.Size)
		return false;

	for (int i = 0; i < Size; i++)
		if (pVector[i] != mt.pVector[i])
			return false;

	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (Size != mt.Size)
	{
		Size = mt.Size;
		delete[] pVector;
		pVector = new TVector<ValType>[mt.Size];
	}

	for (int i = 0; i < Size; i++)
		pVector[i] = mt.pVector[i];

	return *this;


} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	TMatrix<ValType> tmp(*this);

	for (int i = 0; i < Size; i++)
		tmp.pVector[i] = pVector[i] + mt.pVector[i];

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	TMatrix<ValType> tmp(*this);

	for (int i = 0; i < Size; i++)
		tmp.pVector[i] = pVector[i] - mt.pVector[i];

	return tmp;
} /*-------------------------------------------------------------------------*/

