#ifndef CUADRADO_H
#define CUADRADO_H
#include "rectangulo.h"

class cuadrado:public rectangulo
{

    public:
    cuadrado ();
    cuadrado (double lado);
    void imprimir();
};


#endif