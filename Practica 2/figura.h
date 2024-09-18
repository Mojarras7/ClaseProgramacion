#ifndef FIGURA_H//se usa para poder llamar la clase varias veces y que el complidador no marque error
#define FIGURA_H// si no esta definido lo define 

//si no se necesita el include no se pone

class figura
{
// private:
//     float perimetro; //Porque no se usa private????
//     float area;
//     float volumen;
public:
    // figura(/* args */); //tampoco se usa contructor??
    figura();

    virtual double perimetro(); // virtual se refiera a que se permite polimorfismo
    virtual double area();
    virtual double volumen();
    virtual void imprimir();

    
};

#endif
