/* */


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
            if (this -> buscar(clave)) return;

            tabla[clave] = valor;
            cout << "Se inserto: " << clave << " - " << valor << endl;
        }
        bool buscar(const string& clave){
            auto aux = tabla.find(clave);
            if( aux != tabla.end()){
                cout << "Clave consultada: " << clave << " - Valor de la clave: " << aux->second << endl;
                return true;
            } else {
                cout << "Clave no encontrada" << endl;
                return false;
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

        void guardarInfo() {
            ofstream guardar("TablaHashPrueba21.txt", ios::binary);
            if (!guardar) {
                cerr << "Error al abrir el archivo para escritura" << endl;
                return;
            }
            for (const auto& probar : tabla) {
                guardar << probar.first << " " << probar.second << endl;
            }
            guardar.close();
        }

        void cargarInfo() {
            ifstream cargar("TablaHashPrueba21.txt");
            if (!cargar) {
                cerr << "No se pudo abrir el archivo para cargar." << endl;
                return;
            }
            
            string clave;
            int valor;

            while(cargar >> clave >> valor){
                insertar(clave,valor);

            }
            cargar.close();
            cout << "Datos cargados desde hashTable.txt" << endl;
                
            }

};

int main(){
    tablaHash th;


    th.insertar("Samuel", 30);
    th.insertar("Alison", 25);
    th.insertar("Alison", 40);
    th.insertar("Fabiola", 25);
    th.insertar("Aries", 25);
    th.insertar("Alejandra", 25);

    th.imprimirTabla();

    th.guardarInfo(); 


    th = tablaHash(); 
    th.cargarInfo(); 
    th.imprimirTabla(); 
    th.eliminar("Mama");
    th.buscar("Aries");


    return 0;
}