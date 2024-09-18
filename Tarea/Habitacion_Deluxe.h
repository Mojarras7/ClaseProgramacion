#ifndef HABITACION_DELUXE_H
#define HABITACION_DELUXE_H
#include "Habitacion.h"
#include <iostream>

using namespace std;
class Habitacion_Deluxe : public Habitacion {
    private:
    int capacidad;
public:
    Habitacion_Deluxe(int numero);

    double getTarifaBase();
    string toString();

     int getCapacidad();
};

#endif
