#include "cuadrado.h"
#include <iostream>

using namespace std;
cuadrado::cuadrado():cuadrado(5.0){}//manda a llamar al constructor de abajo

cuadrado::cuadrado(double lado):rectangulo(lado, lado){}
void cuadrado::imprimir(){
    cout << "Soy un cuadrado de lado " << base;
}