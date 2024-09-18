//A01644376
//Edwin Alejandro Mojarras Garcia

#include "Pelicula.h"
#include <iostream>
Pelicula::Pelicula(std::string tipo,std::string  id, std::string nombre, int duracion, std::string genero, std::string calificacion)
:id(id), nombre(nombre), duracion(duracion), genero(genero),calificacion(0), numeroCalificaciones(0) {}

std::string Pelicula::getGenero(){
        return genero;
}

float Pelicula::getCalificacion(){
        return calificacion;
}

//setters y getters
void Pelicula::setCalificacion(std::string id, float calificacion) {
    if (this->id == id) {
        try {
            if (calificacion >= 1 && calificacion <= 5) {
                if (this->numeroCalificaciones == 0) {
                    this->calificacion = calificacion;
                } else {
                    float promedioAnterior = this->calificacion;
                    float promedioNuevo = (promedioAnterior * this->numeroCalificaciones + calificacion) / (this->numeroCalificaciones + 1);
                    this->calificacion = promedioNuevo;
                }
                this->numeroCalificaciones++;
                std::cout << "Calificado exitosamente!" << std::endl;
            } else {
                std::cout << "La calificacion debe ser entre 1 y 5" << std::endl;
            }
        } catch (std::invalid_argument&) {
            std::cout << "La calificacion proporcionada no es un numero valido" << std::endl;
        } catch (std::out_of_range&) {
            std::cout << "La calificacion esta fuera del rango" << std::endl;
        }
    } else {
        std::cout << "ID no encontrado" << std::endl;
    }
}



// void Pelicula::imprime(){
//         std::cout << "ID: " << id << ", Nombre: " << nombre << ", Duracion: " << duracion << ", Genero: " << genero << ", Calificacion: " << calificacion << std::endl;
//         }

std::string Pelicula::getId(){
    return id;
}

  // Sobrecarga del operador 
    std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula) {// no funciona sin const
        os << "ID: " << pelicula.id << ", Nombre: " << pelicula.nombre
           << ", Duracion: " << pelicula.duracion << ", Genero: " << pelicula.genero
           << ", Calificacion: " ;

        if (pelicula.calificacion == 0) {
                os << "sc";
        } else {
                os << pelicula.calificacion;
        }
        return os;
    }