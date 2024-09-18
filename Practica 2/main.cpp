#include "figura.h"
#include <iostream>
#include "rectangulo.h"
#include "cuadrado.h"
#include "caja.h"
#include <vector> // un arreglo pero es mas facil de manejar

using namespace std;
int main(){
    vector<figura*> figuras;

    // figura* fig;
    // fig = new figura();

// //     fig.imprimir();
// //     cout << "El perimetro es " << fig.perimetro() << endl;
// //     cout << "El area es " << fig.area() << endl;
// //     cout << "El volumen es " << fig.volumen() << endl;
// //     cout << endl;
//      rectangulo rec1;


// //     fig1.imprimir();
// //      cout << endl;
// //     cout << "El perimetro es " << fig1.perimetro() << endl;
// //     cout << "El area es " << fig1.area() << endl;
// //     cout << "El volumen es " << fig1.volumen() << endl;
// //     cout << endl;

//      rectangulo rec2(12.5, 15.0);

//      //fig2.imprimir();
// //      cout << endl;
// //     cout << "El perimetro es " << fig2.perimetro() << endl;
// //     cout << "El area es " << fig2.area() << endl;
// //     cout << "El volumen es " << fig2.volumen() << endl;
// //     cout << endl;

//     cuadrado cuadrado;

// //     fig3.imprimir();
// //      cout << endl;
// //     cout << "El perimetro es " << fig3.perimetro() << endl;
// //     cout << "El area es " << fig3.area() << endl;
// //     cout << "El volumen es " << fig3.volumen() << endl;
// //     cout << endl;
    
//      caja caja1;

// //     caja1.imprimir();
// //      cout << endl;
// //     cout << "El perimetro es " << caja1.perimetro() << endl;
// //     cout << "El area es " <<  caja1.area() << endl;
// //     cout << "El volumen es " << caja1.volumen() << endl;
// //     cout << endl;
    
//      caja caja2(2, 3, 4);

// //     caja1.imprimir();
// //      cout << endl;
// //     cout << "El perimetro es " << caja2.perimetro() << endl;
// //     cout << "El area es " <<  caja2.area() << endl;
// //     cout << "El volumen es " << caja2.volumen() << endl;
// //     cout << endl;
    

    //esto se hizo para ahorrarnos lineas de codigo
    figuras.push_back(new figura());
    figuras.push_back(new rectangulo());
    figuras.push_back(new rectangulo(2.0, 4.0));
    figuras.push_back(new cuadrado());
    figuras.push_back(new caja());
    figuras.push_back(new caja(1,2,3));
    //el polimorfismo es necesario hacerlo con apuntadores
    //el medoto se llama igual pero hacen diferentes cosas, manda a llamar el metodo especifico de cada clase
    for (int i=0; i<figuras.size(); i++){ // el polmorfismo se necesita para poder hacer 
        figuras[i]->imprimir(); // que figura use sus metodos y no el metodo de la clase padre
        cout << endl;
        cout << "El perimetro es " << figuras[i]->perimetro() << endl;
        cout << "El area es " <<  figuras[i]->area() << endl;
        cout << "El volumen es " << figuras[i]->volumen() << endl;
        cout << endl;
    }
}
//un apuntador es una referencia 
// caja caja2*; no es un objeto como tal
// caja2 = caja1; va a apuntar a caja1