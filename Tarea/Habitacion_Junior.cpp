#include "Habitacion_Junior.h"
#include <iostream>

using namespace std;
Habitacion_Junior::Habitacion_Junior(int numero):Habitacion(numero), capacidad(4){}
//Habitacion_Junior::Habitacion_Junior(int numero) : capacidad(4){}

double Habitacion_Junior::getTarifaBase(){    
   return Habitacion::getTarifaBase()*1.20;
}

string Habitacion_Junior::toString(){
    return Habitacion::toString() + ",Habitacion Junior"; 
}
int Habitacion_Junior::getCapacidad(){    
   return capacidad;
}


