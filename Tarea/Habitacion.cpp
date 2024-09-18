#include "Habitacion.h"
#include <iostream>
//A01644376
//Edwin Mojarras

using namespace std;
Habitacion::Habitacion() : adultos(0), infantes(0), nombre(""), credito(0.0), cargo(0.0), disponible(true){
    //se puede hacer asi pero es mejor una lista de inicializacon
    //  nombre = "";
    //  numero = 0;
    //  adultos = 0;
    // infantes = 0;
    // credito = 0.0;
    //  cargo = 0.0;
    //  habitacion = true;
}   
Habitacion::Habitacion(int numero) : numero(numero), adultos(0), infantes(0), nombre(""), credito(0.0), cargo(0.0), disponible(true) {}

bool Habitacion::checkin(string nombre, int adultos, int infantes, double credito){ // aqui no se puede usar una lista de inicializacion porque no es contructor 
   if (disponible){
        this -> nombre = nombre;
        this -> adultos = adultos;
        this -> infantes = infantes;
        this -> credito = credito;
        this -> cargo = 0.0;
        this -> disponible = false;
        return true; //se hizo el checkin
   } else {
    return false; // la habitacion no esta disponible 
   }
}

bool Habitacion::checkout(){
    if (!disponible){
        nombre = "";
        adultos = 0;
        infantes = 0;
        cargo = 0.0;
        credito = 0.0;
        disponible = true; // se marca la habitacion como disponible 
        return true;
    } else {
        return false;
    }
}
double Habitacion::getTarifaBase() { 
    const double tarifa_adulto = 650.0;
    const double tarifa_infante = 250.0;

    double tarifaBase = (adultos * tarifa_adulto) + (infantes * tarifa_infante);
    return tarifaBase;
}
bool Habitacion::realizarCargo(double cargoAdicional){
    if (cargoAdicional > 0 && (cargo + cargoAdicional)<=credito){
        cargo += cargoAdicional;
        return true;
    }else {
        return false; // el cargo no se pudo hacer
    }
}
string Habitacion::toString(){
    string resultado = to_string(numero) + ",";
    resultado += "Huesped:" + nombre + ",";
    resultado += "Tarifa Base:" + to_string(getTarifaBase()) + ",";
    resultado += "Credito:" + to_string(credito) + ",";
    resultado += "Cargos:" + to_string(cargo);
    return resultado;
}
bool Habitacion::isDisponible() const {
    return disponible; 
}
int Habitacion::getNumero() const {
    return numero;  
}
