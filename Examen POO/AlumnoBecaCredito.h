#include "AlumnoBeca.h"
//A01644376
//Edwin Alejandro Mojarras Garcia
class AlumnoBecaCredito:public AlumnoBeca
{
private:
    double pCredito;
public:
    AlumnoBecaCredito(int matricula, std::string nombre, int unidades);

    //setters
    void setBecaCreditos(double pBeca, double pCredito);

    double getPagoSemestre() override;
    std::string imprimeDatos() override;


};
