#include "Habitacion_Suite.h"

Habitacion_Suite::Habitacion_Suite(int numero) : Habitacion(numero), capacidad(6){}
//Habitacion_Suite::Habitacion_Suite(int numero) : capacidad(6){}

double Habitacion_Suite::getTarifaBase() {
    return Habitacion::getTarifaBase() * 1.30;
}

    
string Habitacion_Suite::toString(){
    return Habitacion::toString() + ",Habitacion Suite"; 
}

int Habitacion_Suite::getCapacidad(){    
   return capacidad;
}