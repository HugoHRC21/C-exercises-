/*Desarrolla un programa que inicialice un vector de enteros con al menos 5 elementos. 
Pide al usuario que ingrese un número y verifica si ese número se encuentra en el vector.
 Si se encuentra, imprime la posición del número; si no, informa que el número no está en el vector.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){

    int y, x;

    vector <int> vector ={34,87,927,2,7,19,9,5,27,21};
    cout << "Ingrese un numero entero para verifcar si se encuentra en el vector:" << endl;
    cin >> y;
    int i = 0;

    while(i < 10){
            if(vector[i] == y){
             cout << "El valor ingresado se encuentra en el vector y esta en la posicion: " << i + 1 << endl;
             x = 1;
            break;
            }
            i++;
        }
    
    if(x!=1){ cout << "El valor ingresado No se encuentra en el vector! \n" <<endl;}


    cout << "Estos eran los valores que contenia el vector: " << endl; 
        for(int i =0; i < 10; i++){
            cout << vector[i] <<" ";
        }

return 0;
}


