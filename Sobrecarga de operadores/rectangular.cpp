#include "rectangular.h"
#include <string>
#include "polar.h"
#include <math.h>
rectangular::rectangular(double x, double y){
    this->x=x;
    this->y=y;
}
rectangular::rectangular():rectangular(0,0){}
double rectangular::getX(){
    return this->x;
    }
double rectangular::getY(){
    return this->y;
}
void rectangular::setX(double x){
    this->x=x;
}
void rectangular::setY(double Y){
    this->y=y;
}
rectangular rectangular::suma(rectangular r1){
    return rectangular(this->x+r1.x, this->y+r1.y);
}
rectangular rectangular::operator+(rectangular r1){
    return rectangular(this->x+r1.x, this->y+r1.y);
}
rectangular rectangular::operator-(rectangular r1){
    return rectangular(this->x-r1.x, this->y=r1.y);
}
rectangular rectangular::operator*(rectangular r1){
    return (this->toPolar()*r1.toPolar()).toRectangular();
}
rectangular rectangular::operator/(rectangular r1){
    return (this->toPolar()/r1.toPolar()).toRectangular();
}
rectangular rectangular::operator+(polar p1){
}
string rectangular::toString(){
    return "("+to_string(this->x) + ","+to_string(this->y)+")";
}
polar rectangular::toPolar(){
    return polar(sqrt(this->x*this->x+this->y*this->y),atan2(this->y,this->x));
}