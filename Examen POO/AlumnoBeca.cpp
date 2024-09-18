#include "AlumnoBeca.h"
//A01644376
//Edwin Alejandro Mojarras Garcia
AlumnoBeca::AlumnoBeca(int matricula, std::string nombre, int unidades, double pBeca):Alumno(matricula, nombre, unidades), pBeca(pBeca){}

double AlumnoBeca::getPagoSemestre(){
    double pagoSemestre;
    pagoSemestre = Alumno::getPagoSemestre()*(1-pBeca);
    return pagoSemestre;
}
std::string AlumnoBeca::imprimeDatos(){
    return Alumno::imprimeDatos() + "," + std::to_string(pBeca*100)  + "%";
}