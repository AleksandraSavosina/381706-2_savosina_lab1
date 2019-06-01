#pragma once
#include <string>
#include  <iostream>

using namespace std;

template <class T>
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
  TPoint(const TPoint& point)
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
