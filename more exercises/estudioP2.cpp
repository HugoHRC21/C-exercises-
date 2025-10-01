/*Escriba un programa que introduzca tres diferentes enteros desde el teclado, después que imprima la suma, el
promedio, el producto, el número más pequeño y el más grande de éstos. Solamente utilice la forma de selección
simple de la instrucción if, que aprendió en este capítulo.*/

#include "iostream"
#include "string"
using namespace std;


int main()
{
    string titulos[5];
    string autores[5];
    cout << "Por favor ingrese la siguiente información de los Libros: \n";
    for(int i = 0; i < 5; i++)
    {
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        getline(cin, titulos[i]);
        cout << "Autor: ";
       getline(cin, autores[i]);
}
}