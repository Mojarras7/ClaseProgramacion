#ifndef ALUMNOBECA_H
#define ALUMNOBECA_H
#include "Alumno.h"
//A01644376
//Edwin Alejandro Mojarras Garcia
class AlumnoBeca:public Alumno
{
protected:
    double pBeca;
public:
    AlumnoBeca(int matricula, std::string nombre, int unidades, double pBeca);

    double getPagoSemestre() override;

    std::string imprimeDatos() override;


};


#endif