#include "Habitacion_Deluxe.h"

Habitacion_Deluxe::Habitacion_Deluxe(int numero) : Habitacion(numero), capacidad(8){}

//Habitacion_Deluxe::Habitacion_Deluxe(int numero) : capacidad(8){}
double Habitacion_Deluxe::getTarifaBase() {
    return Habitacion::getTarifaBase() * 1.50;
}

    
string Habitacion_Deluxe::toString(){
    return Habitacion::toString() + ",Deluxe"; 
}


int Habitacion_Deluxe::getCapacidad(){    
   return capacidad;
}