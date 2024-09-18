#include "Alumno.h"
//A01644376
//Edwin Alejandro Mojarras Garcia
Alumno::Alumno(int matricula, std::string nombre, int unidades){
    this->matricula = matricula;
    this ->nombre = nombre;
    if(unidades < 0 || unidades > 18){
        this->unidades = 0;
    }else{
        this->unidades = unidades;
    }
}
Alumno::Alumno(int matricula, std::string nombre):matricula(matricula),nombre(nombre),unidades(0){}
bool Alumno::incrementaUnidades(int unidades){
    if(unidades < 0 || unidades > 18 ){
        return false;
    }else if (this->unidades + unidades > 18) {
        return false;
    } else {
        this->unidades += unidades;
        return true;
    }
}
int Alumno::getMatricula(){
    return matricula;
}
int Alumno::getUnidades(){
    return unidades;
}
std::string Alumno::getNombre(){
    return nombre;
}
double Alumno::getPagoSemestre(){
    return unidades*9000;
}
std::string Alumno::imprimeDatos(){
    return std::to_string(matricula) + "," + nombre + "," + std::to_string(unidades) + "$" + std::to_string(getPagoSemestre());
}