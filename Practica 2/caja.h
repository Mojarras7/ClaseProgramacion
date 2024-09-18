#ifndef CAJA_H
#define CAJA_H
#include "rectangulo.h"

class caja:public rectangulo
{
protected:
    double alto;
public:
    caja();
    caja(double base, double altura, double alto);
    double perimetro();
    double area();
    double volumen();
    void imprimir();
};


#endif