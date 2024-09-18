#ifndef HABITACION_SUITE_H
#define HABITACION_SUITE_H
#include "Habitacion.h"
#include <iostream>

using namespace std;

class Habitacion_Suite : public Habitacion {
    private:
    int capacidad;
public:
    Habitacion_Suite(int numero);

    double getTarifaBase();
    string toString();

    int getCapacidad();
};

#endif
