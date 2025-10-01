/*Ejercicio 3: Funciones y Procedimientos 
Escribe un programa que implemente funciones para calcular el área y el perímetro de un rectángulo. 
Requisitos: 
1. Implementa dos funciones: 
calcular_area(base, altura) - retorna el área (paso de parámetros por valor). 
calcular_perimetro(base, altura, &perimetro) (paso de parámetros por referencia o puntero). 
2. Solicita al usuario la base y la altura del rectángulo. 
3. Usa las funciones para calcular y mostrar el área y el perímetro. 
Ejemplo de entrada y salida esperada: 
Entrada: 
Base=5, Altura =3 
Salida: 
Área: 15 
Perímetro: 16*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int Area (int base, int altura){
    return base * altura;
}
void Perimetro(int base , int altura , int* perimetro){
    *perimetro = (2*base) + (2*altura);
}


int main(){
    
    int base, altura;
    int perimetro = 0;

    cout << "Ingrese los valores de Base y la Altura del Rectangulo: " << endl;

    do {
        cout << "Base: "; cin >> base;
        cout << "Altura: "; cin >> altura; cout << endl;
    } while( base < 0 || altura < 0);

    
    cout << "Area del Rectangulo: "<< Area(base,altura) << endl;
    Perimetro(base,altura, &perimetro);

    cout << "Perimetro del Rectangulo:  "<< perimetro <<endl;


    return 0;

}