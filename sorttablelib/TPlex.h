// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include <string>

using namespace std;

class TPoint
{
protected:
  double x;
  double y;
public:
  TPoint()
  {
    x = 0;
    y = 0;
  }

  TPoint(const double _x, const double _y)
  {
    x = _x;
    y = _y;
  }
  TPoint(const TPoint& point);
  {
    x = point.x;
    y = point.y;
  }
  ~TPoint() { x = 0;  y = 0; }
  bool operator==(const TPoint& point)
  {
    if (x == point.x && y == point.y)
      return true;
    else
      return false;
  }
  bool operator!=(const TPoint& point)
  {
    if (x == point.x && y == point.y)
      return false;
    else
      return true;
  }
  void SetX(const double _x) { x = _x; }
  void SetY(const double _y) { y = _y; }
  double GetX() { return x; }
  double GetY() { return y; }
  virtual void Show()
  {
    cout << "x = " << x << " y = " << y << endl;
  }
};



class TPlex : public TPoint
{
protected:
  TPoint* right;
  TPoint* left;
public:
  TPlex()
  {
    right = NULL;
    left = NULL;
  }
  TPlex(const TPlex& plex)
  {
    TPlex* tmp1 = TPlex<TPlex*>(plex.left);
    TPlex* tmp2 = TPlex<TPlex*>(plex.right);
    if (tmp1 != NULL)
      left = new TPlex(*tmp1);
    else
      left = new TPoint(*plex.left);
    if (tmp2 != NULL)
      right = new TPlex(*tmp2);
    else
      right = new TPoint(*plex.right);
  }
  TPlex(TPoint* point1, TPoint* point2)
  {
    TPlex* tmp1 = TPlex<TPlex*>(point1);
    TPlex* tmp2 = TPlex<TPlex*>(point2);
    if (tmp1 != NULL)
      left = new TPlex(*tmp1);
    else
      left = new TPoint(*point1);
    if (tmp2 != NULL)
      right = new TPlex(*tmp2);
    else
      right = new TPoint(*point2);
  }


  ~TPlex() {}
  void Delete()
  {
    TPlex* tmp1 = dynamic_cast<TPlex*>(left);
    TPlex* tmp2 = dynamic_cast<TPlex*>(right);
    if (tmp1 != NULL)
      tmp1->Delete();
    else
      delete left;
    if (tmp2 != NULL)
      tmp2->Delete();
    else
      delete right;
  }
};

#endif