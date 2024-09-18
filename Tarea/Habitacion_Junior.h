    #ifndef HABITACION_JUNIOR_H
    #define HABITACION_JUNIOR_H
    #include "Habitacion.h"


    class Habitacion_Junior:public Habitacion
    {
     private:
        int capacidad;
    public:
        Habitacion_Junior(int numero);

        double getTarifaBase();
        string toString();    
        
        int getCapacidad();
    };



    #endif