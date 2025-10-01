/*Desarrolla un programa que implemente el método de ordenamiento por selección. 
El programa debe pedir al usuario que ingrese una lista de k números decimales (de tipo float). 
Ordena la lista de números en orden descendente y muestra el resultado..*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int x,y,min;
    cout << "Ingrese el numero de elementos que desea almacenar: " <<endl;
    cin >> x;

    vector<float>box(x);

    cout << "Ingrese " << x << " numeros decimales: " <<endl;
    for(int i = 0; i < x; i++){
        cin >> box[i];
    }

    for(int i = 0; i < x-1; i++){
        min = i;
        for(int j = i+1; j < x;j++ ){
            if(box[j] < box[min]){
                min = j;
            }
        }
        swap(box[i], box[min]);
    }


    cout << "Estos son los numeros decimales ingresados y ordenados de manera ascendente" << endl;
    for(int i =0; i<x;i++){
        cout<< box[i] << endl ;
    }

    return 0;
}