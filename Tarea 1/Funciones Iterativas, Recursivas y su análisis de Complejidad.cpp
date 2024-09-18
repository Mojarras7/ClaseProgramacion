//A01644376
//Edwin Alejandro Mojarras Garcia
 //Fecha: 1 de septiembre de 2024
 //Act 1.1 - Funciones Iterativas, Recursivas y su análisis de Complejidad
// Descripción: Este programa contiene tres funciones para calcular la suma n números naturales.

#include <iostream>

long long sumaIterativa(int n){ //long long si la suma es muy grande
    long long suma;
    suma = 0;
    if(n <= 0){
        return -1;
    }
    for(int i = 0; i<=n; i++){
        suma += i;
    }
    return suma; 
}; // la complejidad es de o(n) porque el ciclo for depende de n, pero el espacio es o(1) porque todo se almacena en una variable

long long sumaRecursiva(int n){
    if(n<0) return -1; //comprobar la entrada
    if (n == 0) {
        return 0; // caso base
    }
    
    return n + sumaRecursiva(n-1);

}; // la complejidad es de o(n) porque hace una llamada a la funcion depende de n, tambien el espacio es o(n) porque lo que almacena depende de n

long long sumaDirecta(int  n){ //formula de los numeros naturales de gauss
     if (n <= 0) {
        return -1;
    }
    return n * (n + 1) / 2;
    //suma = n*(n + 1)/2
}; // la complejidad es o(1), porque usa solo una operacion para resolver


int main(){
    std::cout << sumaIterativa(10000000000) << std::endl;
    std::cout << sumaRecursiva(-100) << std::endl;
    std::cout << sumaDirecta(100);

}


