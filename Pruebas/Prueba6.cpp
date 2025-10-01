/*Ejercicio 2: Matrices 
Escribe un programa que realice las siguientes operaciones con una matriz cuadrada de orden N x N 
(donde N es ingresado por el usuario, con un valor máximo de 10): 
1. Solicitar al usuario que ingrese los valores de la matriz. 
2. Calcular y mostrar la suma de los elementos de la diagonal principal. 
3. Transponer la matriz e imprimirla. 
4. Determinar si la matriz es simétrica (una matriz es simétrica si es igual a su transpuesta*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


void validate_input(int x) {
    if (x < 0 or x >10)
        throw invalid_argument("invalid value");
}

int main(){
    int x,y=0,aux = 0, z=0;
    do {
        cout << "Ingrese el tamano de la matrix: "<< endl;
        cout << "Tamano cuadrado: "; cin >> x;  
        try{
            validate_input(x);
            break;
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
        
    } while(true);

    int matriz[x][x];

    cout << "ingrese los valores de la matriz: " << endl;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz Original: " << endl;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            cout << matriz[i][j] << "\t"; 

        }
         cout << endl;
    }

    for(int i = 0; i < x; i++){
        y+= matriz[i][i];
    }

    cout << "Valor de la diagonal: " << y << endl;

    for(int i = 0; i < x; i++){
        for(int j = i+1; j < x; j++){
           aux = matriz[i][j];
           matriz[i][j] = matriz[j][i];
           matriz[j][i] = aux;

        }
    }
    cout << endl;

    cout << "Matriz Traspuesta: " << endl;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            cout << matriz[i][j] << "\t"; 

        }
         cout << endl;
    }
        for(int i = 0; i < x; i++){
        z+= matriz[i][i];
    }

    cout << "Nuevo Valor de la Diagonal: " << z << endl;

    if( y == z){
        cout << "La matriz es simetrica! :)" << endl;
    } else {
        cout << "La matriz No es simetrica! :(" << endl;
    }




     return 0;
}


   
