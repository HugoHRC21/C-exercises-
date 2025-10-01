/*Crea un programa que permita al usuario ingresar 6 números enteros en un vector. 
Luego, ordena los elementos del vector en orden ascendente y muestra el vector ordenado en la salida.*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(){


    vector <int> vector(6);
    cout << "Ingrese 6 numeros enteros al vector: " << endl;
    for(int i=0; i < 6; i++){
        cin>>vector[i];
    }

    sort(vector.begin(), vector.end());
    
    cout << "Estos son los valores que ordenados del vector: " << endl;    
    for(int i=0; i < 6; i++ ){
        cout << vector[i] << " ";
    }
   
return 0;

}
