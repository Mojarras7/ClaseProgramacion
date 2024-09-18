#ifndef POLAR_H
#define POLAR_H
#include <ostream>
#include <string>
#include "rectangular.h"

using namespace std;
class polar
{
private:
   double r,
          a;
public:
    polar();
    polar(double r, double a);
    double getR();
    double getA();
    void setR(double r);
    void setA(double a);
    polar operator*(polar p1);
    polar operator/(polar p1);
    rectangular toRectangular();
    friend ostream& operator<<(ostream& os, const polar p1){
        os<<"("<<p1.r<<","<<p1.a<<")";
        return os;
    }
};


#endif