#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "figura.h"

class rectangulo:public figura
{
protected: // se usa para que sea privado y no se pueda acceder a ella, pero sea publico para las clases derivadas
    double base,
           altura; // se pone asi para que el codigo sea mas legible
public:
    rectangulo();
    rectangulo(double base, double altura);

    double perimetro();
    double area();
    void imprimir();
};

#endif
