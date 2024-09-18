#include "caja.h"
#include <iostream>

using namespace std;
caja::caja():caja(6.0, 3.0, 7.0){}

caja::caja(double base, double altura, double alto ):rectangulo(base, altura){ //el constructor padre inicializa base y altura 
    this -> alto = alto;
}
double caja::perimetro(){

return 4.0* this -> base + 2.0*this -> altura + 8.0* this->alto;
}
double caja::area(){
    return 2.0*(rectangulo::area()+(this ->base * this -> alto)+(this ->alto *this->altura));
}
double caja::volumen(){

    return /*this->alto*this->altura*this->base;*/ rectangulo::area()*this->alto; // manda a llar el metodo area del recatngulo

}
void caja::imprimir(){
    cout << "Soy una caja de ancho " << this -> base << " de largo " << this -> altura << " de alto " << this -> alto;
}