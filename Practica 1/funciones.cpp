#include <iostream>
#include <stdlib.h>

using namespace std;

int suma(int a,int b){
    int suma = a + b;
    return suma;
}

void establecer(int &a, int &b){
   b = a;
}

int main(){
    int valor1, valor2;
    cout << "ingrese el valor 1 ";
    cin >> valor1;
    cout << "Ingrese el valor 2 ";
    cin >> valor2;
   

    int valor3, valor4;

    cout << "ahora ingrese otros valores " << endl;
    cin >> valor3;
    cin >> valor4;
    int suma2 = suma(valor3,valor4);
    int suma1= suma(valor1,valor2);
    cout << "Los resultados de las sumas son ";
    cout  << "\nResultado suma 1 " << suma1;
    cout << "\nResultado suma 2 " << suma2 << endl;
 
    cout << "Ahora vamos a establecer que valor 1 y valor 2 son iguales" << endl;
    valor1 = valor2;
    cout << "\nResultado " << suma(valor1, valor2) << endl;
    system("pause");
    return 0;
}