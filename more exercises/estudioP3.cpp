/*Crea un programa que pida al usuario la cantidad de elementos que desea 
ingresar en un vector de enteros. Luego, permite al usuario ingresar los 
elementos del vector y calcula la suma de todos los elementos. Imprime el resultado.*/

#include <iostream>
#include <string>
using namespace std;


int main(){

    int amount;
    int addition = 0;

    cout << "Please enter the number of elements you want to enter in the Vector:" << endl;
    cin >> amount;

    int vector[amount];

    cout << "Ingrese los elementos deseados para ser agregados en el vector: "<< endl;
    for(int i = 0; i < amount; i++ ){

        cin >> vector[i];
        addition += vector[i];
    }
    cout << "The sum of the values ​​entered is:" << addition << endl;

return 0;

}
