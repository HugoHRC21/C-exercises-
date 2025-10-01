/* Implemente una tabla hash en C++ utilizando unordered_map. Su programa debe:

Permitir la inserción de pares clave-valor donde la clave es un string y el valor un int.

Permitir la búsqueda de un valor dado su clave.

Permitir la eliminación de una clave.

Imprimir el contenido completo de la tabla.

Proporcione el código completo y una breve explicación de su funcionamiento.*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <list>
#include <utility>
#include <unordered_map>

using namespace std;

class tablaHash{
    private:
        unordered_map<string, int> tabla;
    public:
        void insertar(const string& clave, int valor){
            tabla[clave] = valor;
            cout << "Se inserto: " << clave << " - " << valor << endl;
        }
        void buscar(const string& clave){
            auto aux = tabla.find(clave);
            if( aux != tabla.end()){
                cout << "Clave consultada: " << clave << " - Valor de la clave: " << aux->second << endl;
            } else {
                cout << "Clave no encontrada" << endl;
            }
        }
        void eliminar (const string& clave){
            if(tabla.erase(clave)){
                cout << "Clave: " << clave << " y su valor eliminados" << endl;
            } else {
                cout << " Clave y su valor no se pudieron eliminar" << endl;
            }
        }
        void imprimirTabla(){
            cout << "Imprmiendo tabla...\n" << endl;
            for(const auto& par : tabla){
                cout << "P: " << par.first << " - " << par.second << endl;
            }
        }
};

int main(){
    tablaHash tablanueva;

    tablanueva.insertar("Mafer", 23);
    tablanueva.insertar("Ale", 28);
    tablanueva.insertar("Julio", 99);
    tablanueva.insertar("Hugo", 67);

    tablanueva.imprimirTabla();

    tablanueva.eliminar("Ale");

    tablanueva.imprimirTabla();

    tablanueva.buscar("Mafer");

    return 0;
}