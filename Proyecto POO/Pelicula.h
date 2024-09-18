//A01644376
//Edwin Alejandro Mojarras Garcia
#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula: public Video
{
private:
    int duracion, numeroCalificaciones;
    std::string nombre,
        genero, 
        id,
        tipo;
    float calificacion;

public:
    Pelicula(std::string tipo, std::string  id, std::string nombre, int duracion, std::string genero, 
    std::string calificacion);

    std::string getGenero() override;
    float getCalificacion() override;

    void setCalificacion(std::string id, float calificacion) override;
    // void imprime() override;
    std::string getId() override;
    friend std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula);

};

#endif