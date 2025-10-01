/*Crea un programa que implemente el método de ordenamiento de burbuja. 
El programa debe pedir al usuario que ingrese un número entero n, 
seguido de n números enteros. Luego, utiliza el algoritmo de burbuja 
para ordenar los números e imprime la lista ordenada.*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    int x,y,z;


    cout << "ingrese el tamano del vector" << endl;
    cin >> x;

    vector<int> container(x);

    cout << "ingrese los elementos del vector" << endl;
    for(int i = 0; i < container.size(); i++){
        cin >> container[i];
    }

    for(int i =0; i < x; i++){
        for(int j = 0; j < x - i - 1; j++){
            if(container[j]>container[j+1]){
                y = container[j];
                container[j] = container[j+1];
                container[j+1] = y;
        }
    }
    }

    cout << "Estos son los elementos ingresados en el vector de manera ascendente" << endl;
    for (int i = 0; i < container.size(); i++){
        cout << container[i] << " ";
    }
    
    return 0;
}