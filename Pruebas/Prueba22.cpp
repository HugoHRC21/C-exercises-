#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <list>
#include <utility>

using namespace std;

class TablaHashBase {
public:
    virtual void insert(const string& key, int value) = 0;
    virtual void remove(const string& key) = 0;
    virtual void buscar(const string& key) = 0;
    virtual void printTable() = 0;
};

class TablaHashPersistente : public TablaHashBase {
private:
    struct KeyValue {
        string key;
        int value;
    };

    vector<list<KeyValue>> table;
    int size;
    int contador = 0;

    void resize() {
        int newTamano = size * 2;
        vector<list<KeyValue>> newTable(newTamano);

        for (int i = 0; i < size; i++) {
            for (const auto& pp : table[i]) {
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
    TablaHashPersistente(int s) : size(s) {
        table.resize(size);
        cargarInfo();
    }

    int hashFunction(const string& key) {
        int hash = 0;
        for (char h : key) {
            hash += static_cast<int>(h);
        }
        return hash % size;
    }

    void insert(const string& key, int value) override {
        if (contador >= size * 0.5) {
            cout << "Redimensionando... (Contador: " << contador << ", Tamaño: " << size << ")" << endl;
            resize();
        }

        int indice = hashFunction(key);
        for (auto& h : table[indice]) {
            if (h.key == key) {
                h.value = value;
                cout << "Valor de '" << key << "' modificado a " << value << endl;
                guardarInfo();
                return;
            }
        }
        table[indice].push_back({key, value});
        contador++;
        guardarInfo();
    }

    void printTable() override {
        for (int i = 0; i < size; i++) {
            cout << "Indice: " << i << ": ";
            for (const auto& h : table[i]) {
                cout << "[ " << h.key << ": " << h.value << " ]";
            }
            cout << endl;
        }
    }

    void buscar(const string& key) override {
        int indice = hashFunction(key);
        for (const auto& b : table[indice]) {
            if (b.key == key) {
                cout << "Clave: " << b.key << " - Valor: " << b.value << endl;
                return;
            }
        }
        cout << "Clave no encontrada" << endl;
    }

    void remove(const string& key) override {
        int indice = hashFunction(key);
        auto& lista = table[indice];

        for (auto it = lista.begin(); it != lista.end(); it++) {
            if (it->key == key) {
                lista.erase(it);
                cout << "Elemento con clave '" << key << "' eliminado" << endl;
                guardarInfo();
                return;
            }
        }
        cout << "Clave '" << key << "' no encontrada" << endl;
    }

    void guardarInfo() {
        ofstream guardar("TablaHashPrueba.txt", ios::binary);
        if (!guardar) {
            cerr << "Error al abrir el archivo para escritura" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            for (const auto& probar : table[i]) {
                guardar << probar.key << " " << probar.value << endl;
            }
        }
        guardar.close();
    }

    void cargarInfo() {
        ifstream cargar("TablaHashPrueba.txt");
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


void menu(TablaHashBase* tabla) {
    int seleccion;
    string key;
    int valor;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insertar\n";
        cout << "2. Leer (Mostrar)\n";
        cout << "3. Buscar\n";
        cout << "4. Eliminar\n";
        cout << "5. Salir\n" << endl;
        cout << "Elige una opción: ";
        cin >> seleccion;

        switch (seleccion) {
        case 1: /*Insertar*/ 
            cout << "Ingrese clave: ";
            cin >> key;
            cout << "Ingrese Valor: ";
            cin >> valor;
            tabla->insert(key, valor);
            break;
        case 2: /*Leer*/
            tabla->printTable();
            break;
        case 3: /*Buscar*/
            cout << "Ingrese clave: ";
            cin >> key;
            tabla->buscar(key);
            break;
        case 4: /*Eliminar*/
            cout << "Ingrese clave: ";
            cin >> key;
            tabla->remove(key);
            break;
        default:
            break;
        }
    } while (seleccion != 5);
};

int main() {
    TablaHashPersistente tabla(10);
    menu(&tabla);

    return 0;
}