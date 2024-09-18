/*
 * Escribe una función que reciba dos palabras (String) y retorne
 * verdadero o falso (Bool) según sean o no anagramas.
 * - Un Anagrama consiste en formar una palabra reordenando TODAS
 *   las letras de otra palabra inicial.
 * - NO hace falta comprobar que ambas palabras existan.
 * - Dos palabras exactamente iguales no son anagrama.
 */
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

bool isAnagram(string iWord, string checkWord){
    char*   charArrayIword = new char[iWord.length()+1]; // esto hace que se haga una array de string que no se va a modificar, es mas eficiente, se llama puntero de caracter 
    // char* es un puntero, hace que la direccion de la memoria se guarde y haga mas efectivo el sistema si es que se va a volver a usar 
    // +1 es para que el ultimo termino del array sea null para que no se limite el string
    charArrayIword[iWord.length()] = '\0';
    for (int i = 0; i < iWord.length(); i++){
        charArrayIword[i] = iWord[i];
    }
    
    //repetimos para crear una array de de caracteres de ahora checkWord
    char* charArrayCheckWord = new char[checkWord.length()+1];
    charArrayCheckWord[checkWord.length()] = '\0';
    for (int i = 0; i < checkWord.length(); i++){
        charArrayCheckWord[i]=checkWord[i];
    }
    cout << charArrayIword << endl;
    cout << charArrayCheckWord << endl;
    int sizeArrayIword =  sizeof(charArrayIword)/sizeof(charArrayIword[0]);
    int sizeArrayCheckWord = sizeof(charArrayCheckWord)/sizeof(charArrayCheckWord[0]); // calcular el tamano del arreglo dividiendo el total de bytes ocupados entre los bytes ocupados por cada elemento
    sort(charArrayIword, charArrayIword + sizeArrayIword); // usa la funcion sort donde el primero es el elemanto a sortear y el segundo es hasta donde se va a sortear 
    sort(charArrayCheckWord, charArrayCheckWord + sizeArrayCheckWord);
    cout << "Arrays sorteados";
    cout << charArrayIword << endl;
    cout << charArrayCheckWord << endl;
    if (sizeArrayIword != sizeArrayCheckWord){
        cout << "NO SON PALABRAS ANALOGAS";
        return 0;
    }
     
    for (int i = 0; i <sizeArrayIword; i++ ){
        int valueIArray = charArrayIword[i], valueArrayCheckWord = charArrayCheckWord[i];
        if (valueIArray != valueArrayCheckWord){
            cout << "LAS PALABRAS NO SON ANALOGAS";
            return 0;
        }
    }
    cout << "LAS PALABRAS SI SON ANALOGAS";
    return 0;
    

    delete[] charArrayIword;
    delete[] charArrayCheckWord;
}

int main(){
    string iWordU, checkWordU;
    cout << "ingrese la palabra inicial " << endl;
    cin >> iWordU;
    cout << "Ingrese la palabra para comprobar si es anagrama" << endl;
    cin >> checkWordU;
    isAnagram(iWordU, checkWordU);
    system("pause");
    return 0;
}
