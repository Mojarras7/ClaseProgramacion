#include "polar.h"
#include <math.h>
polar::polar(double r, double a){
    this->r=r;
    this->a=a;
}
polar::polar():polar(0.0, 0.0){}

double polar::getR(){
    return this->r;
}
double polar::getA(){
    return this->a;
}
void polar::setR(double r){
    this -> r =r;
}
void polar::setA(double a){
    this ->a=a;
}
rectangular polar::toRectangular(){
    return rectangular(sqrt(this->a*this->a+this->r*this->r),atan2(this->r,this->r));
}