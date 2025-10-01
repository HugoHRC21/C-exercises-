/*Ejercicio 3: Manejo de Matrices Dinámicas 
Implementa una clase Matriz que maneje una matriz de enteros de tamaño dinámico. 
Requisitos: 
1. La clase debe permitir: 
Crear una matriz de tamaño mx n (valores ingresados por el usuario). 
Asignar valores aleatorios entre 1 y 100. 
Imprimir la matriz. 
Obtener la transpuesta. 
2. Usa memoria dinámica para almacenar los datos. 
3. En el main, permite al usuario definir el tamaño de la matriz, imprimirla y mostrar su transpuesta.*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;


class Matriz{
    private:
        int** matriz;
        int filas;
        int columnas;
    public:

        void set_filas(int f){
            if(f <= 0) throw invalid_argument("Age must be non-negative");
            this -> filas= f;
        }

        void set_columnas(int c){
            if(c <= 0) throw invalid_argument("Age must be non-negative");
            this -> columnas= c;
        }
        Matriz(int f, int c) {
            
            this->set_filas(f);
            this->set_columnas(c);
            
            matriz = new int*[filas];
            for(int i = 0; i<filas; i++){
                matriz[i] = new int[columnas];
            }

            this->fill_matriz();
        }

        ~Matriz() {
            for (int i = 0; i < filas; i++) {
                delete[] matriz[i]; 
            }
            delete[] matriz;
        }

         void fill_matriz(){
            for(int i = 0; i < filas ; i++){
                for (int j = 0; j < columnas; j++){
                  }
            }
 
         }

         Matriz transpose_matrix() const {
            Matriz tras(columnas, filas);
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    tras.matriz[j][i] = matriz[i][j];
                }
            }
            return tras;
        }

        void print() {
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    cout << matriz[i][j] << "\t"; 
                }
                cout << endl;
            }
        }

};

int main(){
    srand((int) time(NULL));
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    Matriz matriz(m, n); 

    cout << "Original Matriz: "<< endl;;
    matriz.print(); 

    Matriz transpuesta = matriz.transpose_matrix(); 
    cout << "transposed matrix: "<< endl;
    transpuesta.print(); 

    return 0;
}