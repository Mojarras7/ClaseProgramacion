#ifndef HABITACION_H
#define HABITACION_H
#include <iostream>
//A01644376
//Edwin Mojarras

using namespace std;
class Habitacion
{
protected:
    int numero,
        adultos,
        infantes;
    string nombre;
    double credito,
           cargo;
    bool disponible;
public:
    Habitacion();
    Habitacion(int numero);

    //getters
    int getNumero() const; // se pone const para que el compilador entienda que no se va a modificar
    bool isDisponible() const;
    virtual double getTarifaBase()=0;
    //setters
    void setNumero(int newNumero);

    bool checkin(string nombre, int adultos, int infantes, double credito);
    bool checkout();

    bool realizarCargo(double cargo);

    virtual string toString() = 0;
};



#endif