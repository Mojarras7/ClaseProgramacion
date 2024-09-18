#include "Hotel.h"
#include <iostream>
#include "Habitacion_Junior.h"
#include "Habitacion_Suite.h"
#include "Habitacion_Deluxe.h"

//A01644376
//Edwin Mojarras

using namespace std;
Hotel::Hotel(string nombre) : nombre(nombre), numHabitaciones(0) {
    for (int i = 1; i < 40; ++i) {
        habitaciones.push_back(new Habitacion_Junior(100 + i)); 
        habitaciones.push_back(new Habitacion_Suite(200 + i));
        habitaciones.push_back(new Habitacion_Deluxe(300 + i));
        numHabitaciones++;  
    }
}

int Hotel::checkin(const string& nombre, int adultos, int infantes, double credito, int numhabitacion) { // se usa & para no crear una copia de los valores de la clase habitacion 
    for (int i = 0; i < 40; ++i) {
      if (habitaciones[i]->isDisponible() && habitaciones[i]->checkin(nombre, adultos, infantes, credito)) {
            return habitaciones[i] -> getNumero();
        }
    }
    return -1; 
}

bool Hotel::checkout(int numHabitacion) {
    if (numHabitacion < 100 || numHabitacion > 339) {  //comprrobar si existe la habitacion
        return false;
    }
    int iHabitacion = numHabitacion - 100;
    if (!habitaciones[iHabitacion]->isDisponible() && habitaciones[iHabitacion]->checkout()) {
        return true;
    }
    return false;
}

bool Hotel::realizarCargosHabitacion(int numHabitacion, double cargo) {
    int iHabitacion = numHabitacion - 100; 
    if (habitaciones[iHabitacion]->isDisponible()) {
        return false; 
    }
    return habitaciones[iHabitacion]->realizarCargo(cargo);
}

double Hotel::getTotalXTarifaBase() const {
    double total = 0.0;
    for (auto habitacion : habitaciones) {
        if (!habitacion->isDisponible()) {
            total += habitacion->getTarifaBase();
        }
    }
    return total;
}


void Hotel::imprimeOcupacion() const {
    cout << "Ocupacion en " << nombre << endl;

    for (int i = 0; i < 40; ++i) {
            if (!habitaciones[i]->isDisponible()) { 
                cout << habitaciones[i]->toString() << endl;
        }
    }
}
//crea habitacione en el vector
void Hotel::agregarHabitacion(Habitacion* habitacion) {
    habitaciones.push_back(habitacion);
} 

//obtener habitacion
Habitacion* Hotel::getHabitacion(int numHabitacion) const {
    for (int i = 0; i < numHabitaciones; ++i) {
        if (habitaciones[i]->getNumero() == numHabitacion) {
            return habitaciones[i];
        }
    }
    return nullptr; // nullptr se usa para decir que no se encontro la habitacion
}

