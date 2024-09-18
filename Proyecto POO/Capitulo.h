//A01644376
//Edwin Alejandro Mojarras Garcia
#ifndef CAPITULO_H
#define CAPITULO_H

#include "Video.h"

class Capitulo:public Video
{
private:
    std::string nombreSerie;
    int numeroEpisodio;
    int duracion;
    int numeroCalificaciones;
    std::string nombre,
        genero, 
        id,
         tipo;
    float calificacion;

public:
    Capitulo(std::string tipo,  std::string id, std::string nombre, int duracion, std::string genero,
             std::string nombreSerie, int NumeroEpisodio, std::string calificacion);

    std::string getGenero () override;
    float getCalificacion () override ;
    void setCalificacion(std::string id, float calificacion)  override;
    // void imprime() override;
    std::string getId() override;
    friend std::ostream& operator<<(std::ostream& os, const Capitulo& capitulo);
    
};


#endif