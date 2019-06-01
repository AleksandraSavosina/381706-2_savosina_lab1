#pragma once

#include  <string>
#include  <iostream>
#include "TPoint.h"

using namespace std;


template<class T>
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
