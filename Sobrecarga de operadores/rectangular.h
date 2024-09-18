#ifndef RECTANGULAR_H
#define RECTANGULAR_H

#include <ostream>
#include <string>
#include "polar.h"
using namespace std;

class rectangular
{
private:
    double x,
           y;
public:
   rectangular();
   rectangular(double x, double y);
   double getX();
   double getY();
   void setX(double x);
   void setY(double y);
   rectangular suma(rectangular r1);
   rectangular operator +(rectangular r1);
   rectangular operator +(polar p1);
   rectangular operator -(rectangular r1);
   rectangular operator* (rectangular r1);
   rectangular operator/ (rectangular r1);
   string toString();
   polar toPolar();
   friend ostream& operator<<(ostream& os, const rectangular& r1){
    os<<"("<<r1.x<<","<<r1.y<<")";
    return os;
   }
};




#endif