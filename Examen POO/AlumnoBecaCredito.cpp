#include "AlumnoBecaCredito.h"
//A01644376
//Edwin Alejandro Mojarras Garcia
AlumnoBecaCredito::AlumnoBecaCredito(int matricula, std::string nombre, int unidades):AlumnoBeca(matricula, nombre, unidades, 0.0),pCredito(0.0){}


void AlumnoBecaCredito::setBecaCreditos(double pBeca, double pCredito){
    if(pBeca > 0 && pCredito > 0 && pBeca+pCredito<0.9){
        this -> pBeca = pBeca;
        this -> pCredito = pCredito;
    }
}
double AlumnoBecaCredito::getPagoSemestre(){
    double pagoSemestre;
    pagoSemestre = Alumno::getPagoSemestre()*(1-pBeca+pCredito);
    return pagoSemestre;
}

std::string AlumnoBecaCredito::imprimeDatos(){
    return Alumno::imprimeDatos() + "," + std::to_string(pBeca*100)  + "%" + std::to_string(pCredito*100);
}