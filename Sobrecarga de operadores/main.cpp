#include "rectangular.h"
#include <iostream>
#include "polar.h"
using namespace std;

int main(){
    rectangular r1(1.0, 2.0);
    rectangular r2(3.0, 5.0);
    rectangular r3= r1.suma(r2);
    rectangular r4=r2+r3;

    cout<<r3.toString()<<endl;
    cout<<r3<<endl;

    cout<<r4.toString()<<endl;
    cout<<(r1-r2).toString()<<endl;
    cout<<r1-r2<<endl;

    polar p1(5,4.7);
    cout<<p1<<endl;
    rectangular r5(12,5);
    cout <<r5.toPolar()<<endl;
    cout <<r1+p1<<endl;

    return 0;
}