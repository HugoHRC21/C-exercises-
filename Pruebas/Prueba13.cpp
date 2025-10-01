/*Ejercicio 2: Lista Enlazada de Números 
Implementa una lista enlazada simple de enteros en C++. 
Requisitos: 
1. Crea una estructura Nodo con: 
Un valor entero. 
Un puntero al siguiente nodo. 
2. Implementa la clase ListaEnlazada, que debe permitir: 
Insertar un número al final. 
Eliminar un número por su valor. 
Mostrar todos los elementos. 
3. En el main, permite al usuario agregar números, eliminarlos y mostrar la lista. */

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


struct Nodo{
    int valor;
    Nodo* siguiente;

    Nodo(int v): valor(v), siguiente(nullptr){}
};

class linked_list{
    private:
        Nodo* cabeza;
    public:
        linked_list() : cabeza(nullptr) {}
    
        void insertar(int valor) {
            Nodo* nuevoNodo = new Nodo(valor);
            if (cabeza == nullptr) {
                cabeza = nuevoNodo; 
            } else {
                Nodo* actual = cabeza;
                while (actual->siguiente != nullptr) {
                    actual = actual->siguiente; 
                }
                actual->siguiente = nuevoNodo;
            }
        }
        
        bool eliminar(int valor) {
            if (cabeza == nullptr) return false; 
            
                    
            if (cabeza->valor == valor) {
                Nodo* temp = cabeza;
                cabeza = cabeza->siguiente; 
                delete temp; 
                return true;
            }

            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                if (actual->siguiente->valor == valor) {
                    Nodo* temp = actual->siguiente; 
                    actual->siguiente = actual->siguiente->siguiente; 
                    delete temp; 
                    return true;
                }
                actual = actual->siguiente;
            }

            return false;
        }

        void mostrar() const {
            Nodo* actual = cabeza;
            if (actual == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            while (actual != nullptr) {
                cout << actual->valor << " -> ";
                actual = actual->siguiente;
            }
            cout << "nullptr" << endl;
        }

        ~linked_list() {
            while (cabeza != nullptr) {
                Nodo* temp = cabeza;
                cabeza = cabeza->siguiente;
                delete temp;
            }
        }

};

int main(){
    linked_list lista;
    int opcion, valor;

    do {
        cout << "Menu:" << endl;
        cout << "1. insert number" << endl;
        cout << "2. delete number" << endl;
        cout << "3. show the list" << endl;
        cout << "4. exit" << endl;
        cout << "Select an option:: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Enter a number to insert: ";
                cin >> valor;
                lista.insertar(valor);
                break;
            case 2:
                cout << "Enter a number to delete: ";
                cin >> valor;
                cout << (lista.eliminar(valor) ? "Element deleted" : "Element not found") << "\n";
                break;
            case 3:
                lista.mostrar();
                break;
            case 4:
                cout << "Bye:)" << endl;
                break;
            default:
                cout << "Invalid option, try again:)" << endl;
        }
    } while (opcion != 4);

}
