#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <list>
#include <utility>

using namespace std;

class hashTable{
    private:
        struct KeyValue{
        string key;
        int value;
        };

        vector<list<KeyValue>> table;
        int size;
        int contador = 0;

        void resize(){
            int newTamano = size *2;
            vector<list<KeyValue>> newTable(newTamano);

            for(int i= 0; i < size; i++){
                for(auto& pp : table[i]){
                    int newIndice = hashFunction(pp.key) % newTamano;
                    newTable[newIndice].push_back(pp);
                }
            }

            table.resize(newTamano);
            table = move(newTable);

            size = newTamano;
            cout << "Tabla hash redimensionada a " << newTamano << " exitosamente" << endl;
        }

    public:
        hashTable(int s) : size(s){
            table.resize(size);
            cargarInfo();
        }

        int hashFunction(const string& key){
            int hash = 0;
            for (char h : key){
                hash += static_cast<int>(h);
            }
            return hash % size;
        };

        void insert (const string& key, int value){
            if(contador >= size * 0.5){
                cout << "Redimensionando... (Contador: " << contador << ", Tamaño: " << size << ")" << endl;
                resize();
            }

            int indice = hashFunction(key);
            for(auto& h : table[indice]){
                if(h.key == key){
                    h.value = value;
                    cout << "Valor de '" << key << "' modificado a " << value << endl;
                    guardarInfo();
                    return;
                }
            }
            table[indice].push_back({key,value});
            contador++;
            guardarInfo();
        };

        void printTable(){
            for(int i = 0; i < size; i++){
                cout << "Indice: " << i << ": ";
                for(const auto& h : table[i]){
                    cout << "[ " << h.key << ": " << h.value << " ]";
                }
                cout << endl;
            }
        }

        void Buscar(const string& clave){
            int indice = hashFunction(clave);
            for(auto& b : table[indice]){
                if(b.key == clave){
                    cout << "Clave: " << b.key << " - Valor: " << b.value << endl;
                    return;
                }
            }
            cout << "Clave no coincide con ningun Par Clave-Valor almacenado" << endl;
        }

        void remove(const string& key){
            int indice = hashFunction(key);
            auto& Mientras = table[indice];

            for(auto h = Mientras.begin(); h != Mientras.end(); h++){
                if(h->key == key){
                    Mientras.erase(h);
                    cout << "Elemento con clave '" << key << "' eliminado"<< endl;
                    guardarInfo();
                    return;
                }
            }
            cout << "Clave '" << key << "' no encontrada" << endl;
        }

        void guardarInfo(){
            ofstream guardar("hashTable.txt", ios::binary);
            if(!guardar){
                cerr << "Error al abrir el archivo para Escritura" << endl;
            }

            for(int i=0; i< size; i++){
                for(const auto& probar : table[i]){
                    guardar << probar.key << " " << probar.value << " " << endl;
                }
            }
            guardar.close();
        }
        
        void cargarInfo() {
            ifstream cargar("hashTable.txt");
            if (!cargar) {
                cerr << "No se pudo abrir el archivo para cargar." << endl;
                return;
            }
                string key;
                int value;
                while (cargar >> key >> value) {
                    insert(key, value);
                }
                cargar.close();
                cout << "Datos cargados desde hashTable.txt" << endl;
        }
    };

        void menu(hashTable& tabla){
            int seleccion;
            string key;
            int valor;
            
            do{
                cout << "\nMenu:\n";
                cout << "1. Insertar\n";
                cout << "2. Leer (Mostrar)\n";
                cout << "3. Buscar\n";
                cout << "4. Modificar\n";
                cout << "5. Eliminar\n";
                cout << "6. Salir\n" << endl;
                cout << "Elige una opción: ";
                cin >> seleccion;
        
                switch (seleccion)
                {
                case 1: /*insertar*/
                     cout << "Ingrese clave: ";
                     cin >> key;
                     cout << "Ingrese Valor: ";
                     cin >> valor;
                     tabla.insert(key,valor);
                    break;
                case 2: /*leer*/
                     cout << "Tabla hash en el archivo: "<< endl;
                     tabla.printTable();
                    break;
                case 3: /*Buscar*/
                    cout << "Ingrese clave: ";
                    cin >> key;
                    tabla.Buscar(key);
                    break;
                case 4: /*Modificar*/
                    cout << "Ingrese clave: ";
                    cin >> key;
                    cout << "Ingrese Valor: ";
                    cin >> valor;
                    tabla.insert(key,valor);
                    break;
                case 5: /*eliminar*/
                    cout << "Ingrese clave: ";
                    cin >> key;
                    tabla.remove(key);
                    break;       
                default:
                    break;
                }
            } while (seleccion != 6);
        }




int main(){
    hashTable tabla(10);
    menu(tabla);

    return 0;
}