#include "Alumno.h"
#include "AlumnoBeca.h"
#include "AlumnoBecaCredito.h"
//A01644376
//Edwin Alejandro Mojarras Garcia
int main(){
    Alumno alumno(123, "edwin", 14);
    AlumnoBeca alumno1(345, "alejandro", 12, .8);
    AlumnoBecaCredito alumno2(123, "Edwin", 14);
    alumno2.setBecaCreditos(0.4, 0.3);

    
    std::cout << alumno.imprimeDatos() << std::endl;
    std::cout << alumno1.imprimeDatos() << std::endl;
     std::cout << alumno2.imprimeDatos() << std::endl;
}