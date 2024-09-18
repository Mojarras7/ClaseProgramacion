//A01644376
//Edwin Alejandro Mojarras Garcia
#include "Video.h"
#include "Capitulo.h"
#include "Pelicula.h"
//incluir clases 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> 

using namespace std;

vector<Video*> catalogo;

//vector para almacenar los videos

//crear peliculas 
void crearPelicula(string& linea) {
    string tipo, id;
    int duracion;
    string nombre, genero, calificacion;

    //procesa cada linea
    stringstream ss(linea);

    // leer los valores
    getline(ss, tipo, ','); // leer hasta la coma
    getline(ss, id, ',');
    getline(ss, nombre, ','); 
    ss >> duracion;
    ss.ignore(); // ignora la coma despues de duracion
    getline(ss, genero, ','); 
    getline(ss, calificacion); 

    //almacenar las peliculas
    Pelicula* pelicula = new Pelicula(tipo, id, nombre, duracion, genero, calificacion);
    catalogo.push_back(pelicula);
   
}
//crear capitulos
void crearCapitulo(string& linea) {
    string tipo, id;
     int duracion, numeroEpisodio;
    string nombre, genero, nombreSerie, calificacion;

    stringstream ss(linea);

    getline(ss, tipo, ','); 
    getline(ss, id, ',');
    getline(ss, nombre, ','); 
    ss >> duracion;
    ss.ignore(); 
    getline(ss, genero, ','); 
    getline(ss, nombreSerie, ','); 
    ss >> numeroEpisodio;
    ss.ignore(); 
    getline(ss, calificacion); 

    //almacenar capitulos
    Capitulo* capitulo = new Capitulo(tipo, id, nombre, duracion, genero, nombreSerie, numeroEpisodio, calificacion);
    catalogo.push_back(capitulo);
  
}


int main(){
    //cargar archivo
    ifstream videos("videos.txt", ios::app);
    string linea;
    if(!videos.is_open()){
        cout << "\nError al cargar el archivo intente de nuevo" << endl;
        return 0;
    }else{
        while (getline(videos,linea)) {
            char tipo = linea[0]; // verificar si el primer caracter es p o c

            if (tipo == 'p') {
                crearPelicula(linea);
            } else if (tipo == 'c') {
                crearCapitulo(linea);
            } else {
                cerr << "Error: Tipo desconocido en la linea: " << linea << std::endl;
            }
        }
        videos.close(); // ya se crearon todos los objetos
    }
    
    //menu principal
    cout << "------------------------";
    cout << "\nBienvenido!" << endl;
    int opcion;
    do {
        cout << "------------------------";
        cout << "\nSeleccione una opcion:" << endl;
        cout << "\n1.Mostrar todo el catalogo con calificaciones.";
        cout << "\n2.Calificar un video.";
        cout << "\n3.Mostrar peliculas o capitulos con una calificacion minima determinada.";
        cout << "\n4.Mostrar peliculas o capitulos de un cierto genero.";
        cout << "\n9.Salir.";
        cout << "\n------------------------" << endl;
        cout << "Ingrese el numero de opcion que desea: ";
        //si se ingresa un valor que no es un numero
         try {
            if (!(cin >> opcion)) {
                throw invalid_argument("Volviendo al menu... Recuerda que tu opcion debe de ser un numero entero");
            }
        } catch (invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); 
            cin.ignore();
            opcion = 0; 
            continue;
        }
        cout << "------------------------" << endl;
    
        switch (opcion)
        {
        case 1:{
        //mostrar todo
        cout << "Mostrando todos los videos" << endl;
        for(Video* video: catalogo){
          if (Pelicula* pelicula = dynamic_cast<Pelicula*>(video)) {
                cout << *pelicula << endl; 
          } else if (Capitulo* capitulo = dynamic_cast<Capitulo*>(video)) {
                cout << *capitulo << endl; 
          }
        }
        cout << "Para regresar el menu presione cualquier tecla, [9] para salir: ";
        cin >> opcion;
            break;
        }
        case 2: {
            // Calificar video
            string id,  calificacionStr;
            cout << "Ingrese el ID del video a calificar: ";
            cin >> id;
            cin.ignore();
            bool encontrado = false;
            for (Video* video : catalogo) {
                if (video->getId() == id) {
                    encontrado = true;
                    cout << "\nIngrese una calificacion del 1 al 5: ";
                    getline(cin, calificacionStr);
                    try {
                        float calificacion = stof(calificacionStr); //convierte a float
                        if (calificacion >= 1 && calificacion <= 5) {
                            video->setCalificacion(id, calificacion);
                        } else {
                            cout << "La calificacion debe ser entre 1 y 5" << endl;
                        }
                    } catch (invalid_argument&) {
                        cout << "La calificacion proporcionada no es un numero valido." << endl;
                    } catch (out_of_range&) {
                        cout << "La calificacion proporcionada esta fuera del rango permitido." << endl;
                    }
                    
                    break; 
                }
            }
            if (!encontrado) {
                cout << "No se encontro el video que buscaba. Intente de nuevo." << endl;
            }
            cout << "Para regresar el menu presione cualquier tecla, [9] para salir: ";
            cin >> opcion;
            break;
        }
        case 3:{
        //mostrar por calificacion
            int tipoOpcion;
            float calMin;
            cout << "Seleccione que desea ver" << endl;
            cout << "\n1.Pelicula";
            cout << "\n2.Capitulo";
            cout << "\n3.Ambos";
            cout << "\nIngrese su opcion: ";
            cin >> tipoOpcion;
            cout << "\nIngrese la calificacion minima que desea ver: ";
            cin >> calMin;
             if (calMin < 1 || calMin > 5) {
                cout << "Calificacion invalida. Debe estar entre 1 y 5." << endl;
                break;
            }
            //verificar que si se haga asi 
            switch (tipoOpcion)
            {
            case 1:
                //mostrar peliculas por calificacion
                cout << "Mostrando peliculas con calificacion mayor o igual a " << calMin << ":" << endl;
                for (Video* video : catalogo) {
                    if (Pelicula* pelicula = dynamic_cast<Pelicula*>(video)) {
                    float calificacion = pelicula->getCalificacion();
            
                        if (calificacion != 0) {
                            try {
                                if (calificacion >= calMin) {
                                    cout << *pelicula << endl;
                                }
                            } catch (invalid_argument& e) {
                            cerr << "Error " << e.what() << endl;
                            }   
                        }
                    }
                }
                break;
            case 2:
                //mostrar capitulos por calificacion
                cout << "Mostrando capítulos con calificación mayor o igual a " << calMin << ":" << endl;
                for (Video* video : catalogo) {
                    if (Capitulo* capitulo = dynamic_cast<Capitulo*>(video)) {
                       float calificacion = capitulo->getCalificacion();
                        if (calificacion != 0) {
                            try {

                                if (calificacion >= calMin) {
                                    cout << *capitulo << endl;
                                }
                            } catch (invalid_argument& e) {
                                cerr << "Error " << e.what() << endl;
                            }
                        }
                    }
                }
                break;
            case 3:
               cout << "Mostrando peliculas y capitulos con calificacion mayor o igual a " << calMin << ":" << endl;
               for (Video* video : catalogo) {
                if (Pelicula* pelicula = dynamic_cast<Pelicula*>(video)) {
                    float calificacion = pelicula->getCalificacion();
                    if (calificacion != 0) {
                        try {
                            if (calificacion >= calMin) {
                                cout << *pelicula << endl;
                            }
                        } catch (invalid_argument& e) {
                            cerr << "Error " << e.what() << endl;
                        }
                    }
                    } else if (Capitulo* capitulo = dynamic_cast<Capitulo*>(video)) {
                       float calificacion = capitulo->getCalificacion();
                        if (calificacion != 0) {
                            try {
                                if (calificacion >= calMin) {
                                    cout << *capitulo << endl;
                                }
                            } catch (invalid_argument& e) {
                                cerr << "Error " << e.what() << endl;
                            }
                        }
                    }
                }
                cout << " Para regresar el menu presione cualquier tecla, [9] para salir: ";
                cin >> opcion;
                break;
            default:
                //en caso de que se ingrese una opcion invalida
                cout << "\nLo siento ingrese una opcion valida" << endl;
                break;
            }
            cout << "Para regresar el menu presione cualquier tecla, [9] para salir: ";
            cin >> opcion;
            break;
        }
        case 4: {
        //mostrar por genero
            string genero;
            int opcionTipo;
            cout << "Seleccione que desea ver" << endl;
            cout << "\n1.Pelicula";
            cout << "\n2.Capitulo";
            cout << "\n3.Ambos";
            cout << "\nIngrese su opcion: ";
            cin >> opcionTipo;
            cout << "\nIngrese el genero que desea ver: ";
            cin.ignore(); 
            getline(cin, genero);
            for (Video* video : catalogo) {
                //convertir el genero ingresado a minusculas
                string generoVideo = video->getGenero();
                transform(generoVideo.begin(), generoVideo.end(), generoVideo.begin(), ::tolower);
                transform(genero.begin(), genero.end(), genero.begin(), ::tolower);

                if (generoVideo == genero) {
                    if (opcionTipo == 1 && dynamic_cast<Pelicula*>(video) != nullptr) {
                        cout << *dynamic_cast<Pelicula*>(video) << endl; // Mostrar pelicula si es del tipo
                    } else if (opcionTipo == 2 && dynamic_cast<Capitulo*>(video) != nullptr) {
                       cout << *dynamic_cast<Capitulo*>(video) << endl; 
                    } else if (opcionTipo == 3) {
                        //mostrar ambos
                        if (dynamic_cast<Pelicula*>(video) != nullptr) {
                            cout << *dynamic_cast<Pelicula*>(video) << endl;
                        } else if (dynamic_cast<Capitulo*>(video) != nullptr) {
                            cout << *dynamic_cast<Capitulo*>(video) << endl;
                        } 
                    }
                }
            }
            cout << "Para regresar el menu presione cualquier tecla, [9] para salir: ";
            cin >> opcion;
            break;
        }
        case 9: 
        //salir del programa
            cout << "\nSaliendo del programa..."<<endl;
            break;
        default:
            break;
        }
    }while (opcion != 9);
    return 0;
    
}