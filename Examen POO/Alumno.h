#ifndef ALUMNO_H
#define ALUMNO_H
//A01644376
//Edwin Alejandro Mojarras Garcia
#include <iostream>
class Alumno
{
protected:
    int matricula,
        unidades;
    std::string nombre;
public:
    Alumno(int matricula, std::string nombre, int unidades);
    Alumno(int matricula, std::string nombre);//inicializa todo menos credito
    bool incrementaUnidades(int unidades);

    //getters
    int getMatricula();
    int getUnidades();
    std::string getNombre();
    virtual double getPagoSemestre();

    virtual std::string imprimeDatos();

};

#endif
