#include "rectangulo.h"
#include <iostream>

using namespace std; 

rectangulo::rectangulo():rectangulo(1,2){} //se inicializan los valores pero llamamos al constructor que puede inicializar los valores
rectangulo::rectangulo(double base, double altura){
    /*base = base
    altura = altura, esto no funciona porque las variables se llaman igual
    y se refieren al mismo, que es el que esta desarrollado en la funcion*/
    this -> base = base; // es un puntero al mismo objeto 
    this -> altura = altura;
}
double rectangulo::perimetro(){
    return 2.0*(this -> base + this ->altura);
}
double rectangulo::area(){
    return this -> base * this -> altura;
}
void rectangulo::imprimir(){
    cout << "Soy un rectangulo de altura " << this -> altura << " de base " << this -> base;
}