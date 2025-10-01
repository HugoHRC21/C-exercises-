/*Escribe un programa que utilice el método de ordenamiento por inserción. 
El programa debe solicitar al usuario que ingrese una lista de m nombres (como cadenas de texto).
 Ordena los nombres alfabéticamente y muestra la lista ordenada.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int tamano,j;
    string key;

    cout << "ingrese el numero de nombres que desea almacenar: " << endl;
    cin >> tamano;

    vector<string> caja(tamano);

    cout << "ingrese los " << tamano << " nombres que desea almacenar: " <<endl;
    for(int i = 0; i < tamano; i++){
        cin >> caja[i];
    }

    for(int i = 1; i < tamano; i++){
        key = caja[i];
        j = i-1;

        while(j >= 0 and caja[j]>key){
            caja[j+1] = caja[j];
            j--;
        }
        caja[j+1]=key;
    }

    cout << "Estos son los nombres registrados y ordenados alfabeticamente: " << endl;
    for(int i = 0; i < tamano; i++){
        cout << caja[i] << " " << endl;
    }


    return 0;
}