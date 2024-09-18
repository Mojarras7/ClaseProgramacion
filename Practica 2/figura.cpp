#include "figura.h"
#include <iostream>

using namespace std;

figura::figura(){

}
double figura::perimetro(){
    return 0.0;
}
double figura::area(){
    return 0.0;
}
double figura::volumen(){
    return 0.0;
}
void figura::imprimir(){
    cout << "Soy una figura abstracta" <<endl;
}