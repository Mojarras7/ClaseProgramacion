#ifndef HOTEL_H
#define HOTEL_H
#include "Habitacion.h"
#include <iostream>
#include <vector> //se usa vector porque es mucho mas facil de manejar para toda las implementaciones en el codigo
//A01644376
//Edwin Mojarras
using namespace std;
class Hotel
{
private:
    int numHabitaciones;
    string nombre;

    vector<Habitacion*> habitaciones; //un vector de punteros

public:
    Hotel(string nombre);

    int checkin(const string& nombre, int adultos, int infantes, double credito, int numHabitacion );
    bool checkout(int numHabitacion);
    bool realizarCargosHabitacion(int numHabitacion, double cargo);
    //para agregra habitaciones
    void agregarHabitacion(Habitacion* habitacion);
    
    double getTotalXTarifaBase() const;

    void imprimeOcupacion() const;

     Habitacion* getHabitacion(int numHabitacion) const; //se usa un puntero ya que habitacion es una clase abastracta

};



#endif