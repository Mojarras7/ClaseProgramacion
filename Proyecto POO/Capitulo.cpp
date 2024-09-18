//A01644376
//Edwin Alejandro Mojarras Garcia
#include "Capitulo.h"

Capitulo::Capitulo(std::string tipo, std::string id, std::string nombre, int duracion, std::string genero,
                   std::string nombreSerie, int numeroEpisodio, std::string calificacion)
    : id(id), nombre(nombre), duracion(duracion), genero(genero),
    nombreSerie(nombreSerie), numeroEpisodio(numeroEpisodio), calificacion(0), numeroCalificaciones(0){}

//seters y getters
std::string Capitulo::getGenero(){
      return genero;
}

float Capitulo::getCalificacion(){
      return calificacion;
}

void Capitulo::setCalificacion(std::string id, float calificacion) {
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



// void Capitulo::imprime(){
//      std::cout << "ID: " << id << ", Nombre: " << nombre << ", Duracion: " << duracion
//                   << ", Genero: " << genero << ", NombreSerie: " << nombreSerie << ", NumeroEpisodio: " << numeroEpisodio
//                   << ", Calificacion: " << calificacion << std::endl;
// }

std::string Capitulo::getId(){
    return id;
}

 // Sobrecarga del operador << 
std::ostream& operator<<(std::ostream& os, const Capitulo& capitulo) { // no funciona sin const
    os << "ID: " << capitulo.id << ", Nombre: " << capitulo.nombre
       << ", Duracion: " << capitulo.duracion << ", Genero: " << capitulo.genero
       << ", NombreSerie: " << capitulo.nombreSerie << ", NumeroEpisodio: " << capitulo.numeroEpisodio
       << ", Calificacion: ";
    
    if (capitulo.calificacion == 0) {
        os << "sc";
    } else {
        os << capitulo.calificacion;
    }

    return os;
}