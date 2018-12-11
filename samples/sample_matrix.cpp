// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <ctime>
//---------------------------------------------------------------------------

void main()
{
	int n;

	setlocale(LC_ALL, "Russian");

	cout << "Введите размер матрицы" << endl;
	cin >> n ;
	TVector<int> f(n);
	TMatrix<int> a(n), b(n), c(n);
	int i, j;

	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц"
		<< endl;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}

	long float start_time = clock();
	c = a + b;
	long float end_time = clock();

	cout << "Сложение матриц:" << endl;
	long float search_time = end_time - start_time;
	cout << search_time << " миллисекунд" << endl;	// 1 сек = 1000 милисек

	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
}
