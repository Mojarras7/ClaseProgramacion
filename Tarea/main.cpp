#include "Hotel.h"
#include "Habitacion_Junior.h"
#include "Habitacion_Suite.h"
#include "Habitacion_Deluxe.h"
#include <iostream>

//A01644376 
//Edwin Mojarras

using namespace std;

int main(){

    //crear hotrl
    Hotel Hotel("Hotel Mojarras");

    int numJunior,
        numSuite, 
        numDeluxe;
    cout << "Bienvenido" << endl; 
    cout << "Ingrese la cantidad de habitaciones junior que desea " << endl;
    cin >> numJunior;
    cout << "Ingrese la cantidad de habitaciones suite que desea " <<endl;
    cin >> numSuite ;
    cout << "Ingrese la cantidad de habitaciones deluxe que desea" <<endl;
    cin >> numDeluxe;

    // Crear habitaciones
    for (int i = 0; i < numJunior; ++i) {
        Hotel.agregarHabitacion(new Habitacion_Junior(100 + i));
    }
    for (int i = 0; i < numSuite; ++i) {
        Hotel.agregarHabitacion(new Habitacion_Suite(200 + i));
    }
    for (int i = 0; i < numDeluxe; ++i) {
        Hotel.agregarHabitacion(new Habitacion_Deluxe(300 + i));
    }
    
    int opcion;

    //menu principal
    //se repite hasta que el usuario pique 6
    do {
        cout << "\nMenu:" << endl;
        cout << "1) Hacer check-in" << endl;
        cout << "2) Hacer check-out " << endl;
        cout << "3) Realizar cargos a habitacion " << endl;
        cout << "4) Ingresos por tarifas " << endl;
        cout << "5) Generar reporte de ocupacion " << endl;
        cout << "6) Salir " << endl;
        cout << "Selecciona una opcion: ";
     
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Realizar checkin
                string nombre;
                int adultos, infantes, tipoHabitacion;
                double credito;
                cout << "Ingrese el nombre (solo uno) ";
                cin >> nombre;
                cout << "Ingrese cantidad de adultos ";
                cin >> adultos;
                cout << "Ingrese cantidad de infantes ";
                cin >> infantes;
                cout << "Ingrese el credito disponible ";
                cin >> credito;
    
                cout << "Seleccione el tipo de habitacion:" << endl;
                cout << "1) Junior" << endl;
                cout << "2) Suite" << endl;
                cout << "3) Deluxe" << endl;
                cout << "Selecciona una opcion: " << endl;
               
                cin >> tipoHabitacion;
                int capacidadHabitacion = 0;
                int habitacionAsignada = -1;
                // Verificar si el numero total de huespedes es menor que la capacidad de la habitacion
                //habitacion junior
                if (tipoHabitacion == 1) {
                    for (int i = 0; i < numJunior; ++i) {
                        Habitacion* habitacion = Hotel.getHabitacion(100 + i);
                        //dynamic cast convierte la clase base a la derivada
                        Habitacion_Junior* habitacionJunior = dynamic_cast<Habitacion_Junior*>(habitacion);
                        if (habitacionJunior && habitacionJunior->isDisponible()) {
                            capacidadHabitacion = habitacionJunior->getCapacidad(); 
                            if (adultos + infantes <= capacidadHabitacion) {
                                habitacionAsignada = 100 + i;
                                break;
                            }
                        }
                    }
                    //habitacion suite
                } else if (tipoHabitacion == 2) {
                    for (int i = 0; i < numSuite; ++i) {
                        Habitacion* habitacion = Hotel.getHabitacion(200 + i);
               
                        Habitacion_Suite* habitacionSuite = dynamic_cast<Habitacion_Suite*>(habitacion);
                        if (habitacionSuite && habitacionSuite->isDisponible()) {
                            capacidadHabitacion = habitacionSuite->getCapacidad();
                            if (adultos + infantes <= capacidadHabitacion) {
                                habitacionAsignada = 200 + i;
                                break;
                            }
                        }
                    }
                    //habitacion deluxe
                } else if (tipoHabitacion == 3) {
                    for (int i = 0; i < numDeluxe; ++i) {
                        Habitacion* habitacion = Hotel.getHabitacion(300 + i);
                        Habitacion_Deluxe* habitacionDeluxe = dynamic_cast<Habitacion_Deluxe*>(habitacion);
                        if (habitacionDeluxe && habitacionDeluxe->isDisponible()) {
                            capacidadHabitacion = habitacionDeluxe->getCapacidad();
                            if (adultos + infantes <= capacidadHabitacion) {
                                habitacionAsignada = 300 + i;
                                break;
                            }
                        }
                    }
                } else {
                    cout << "Tipo de habitacion invalido" <<endl;
                    break;
                }

                if (habitacionAsignada == -1) {
                    cout << "No hay habitaciones disponibles de este tipo o excede la capacidad " << endl;
                } else if (adultos + infantes > capacidadHabitacion) {
                    cout << "Excede la capacidad de la habitacion. Intente con otro tipo de habitacion." << endl;
                } else {
                    if (Hotel.checkin(nombre, adultos, infantes, credito, habitacionAsignada)) {
                        cout << "Check-in exitoso. Habitacion asignada: " << habitacionAsignada << endl;
                    } else {
                        cout << "Error al realizar el check-in." << endl;
                    }
                }
                break;
            }
            case 2: {
                int numeroHabitacion;
                cout << "Ingrese el numero de habitacion para realizar check-out: "<< endl;
                cin >> numeroHabitacion;
                if (Hotel.checkout(numeroHabitacion)) {
                    cout << "Check-out exitoso." << endl;
                } else {
                    cout << "No se pudo realizar el check-out. Habitacion no encontrada" << endl;
                }
                break;
            }
            case 3: {
                // Realizar cargos 
                int numeroHabitacion;
                double cargo;
                cout << "Ingrese el numero de habitacion: ";
                cin >> numeroHabitacion;
                cout << "Ingrese el monto del cargo: ";
                cin >> cargo;
                if (Hotel.realizarCargosHabitacion(numeroHabitacion, cargo)) {
                    cout << "Cargo realizado exitosamente." << endl;
                } else {
                    cout << "No se pudo realizar el cargo." << endl;
                }
                break;
            }
            case 4: {
                // Mostrar ingresos por tarifas
                cout << "Ingresos por tarifas: $" << Hotel.getTotalXTarifaBase() << endl;
                break;
            }
            case 5: {
                // Reporte de ocupacion
                Hotel.imprimeOcupacion();
                break;
            }
            case 6:
                cout << "Saliendo del sistema" << endl;
                break;
            default:
                cout << "Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 6);

    return 0;

}
