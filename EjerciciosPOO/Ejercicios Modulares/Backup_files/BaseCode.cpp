#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

// Estructura para almacenar la información de una persona
struct Persona {
    string nombre;
    int edad;
    string carrera;
    string id;

    string toString() const {
        return nombre + "," + to_string(edad) + "," + carrera + "," + id;
    }
};

// Clase para la tabla hash
class TableHash {
private:
    vector<list<Persona>> tabla;
    int tamano;

    int hashFunction(const string& id) {
        int hash = 0;
        for (char c : id) {
            hash += c;
        }
        return hash % tamano;
    }
    
public:
    TableHash(int tam) : tamano(tam) {
        tabla.resize(tamano);
    }

    void insertar(const Persona& persona) {
        int indice = hashFunction(persona.id);
        tabla[indice].push_back(persona);
    }

    bool buscar(const string& id, Persona& persona) {
        int indice = hashFunction(id);
        for (const auto& p : tabla[indice]) {
            if (p.id == id) {
                persona = p;
                return true;
            }
        }
        return false;
    }

    void eliminar(const string& id) {
        int indice = hashFunction(id);
        tabla[indice].remove_if([&id](const Persona& p) {
            return p.id == id;
        });
    }

    vector<Persona> obtenerTodos() const {
        vector<Persona> personas;
        for (const auto& lista : tabla) {
            for (const auto& p : lista) {
                personas.push_back(p);
            }
        }
        return personas;
    }
};

// Funciones para manejar el archivo
void cargarDatos(TableHash& tabla, const string& nombreArchivo) {
    ifstream file(nombreArchivo);
    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        Persona persona;
        getline(ss, persona.nombre, ',');
        ss >> persona.edad;
        ss.ignore(1); // Ignorar la coma
        getline(ss, persona.carrera, ',');
        getline(ss, persona.id, ',');
        tabla.insertar(persona);
    }
}

void guardarDatos(const TableHash& tabla, const string& nombreArchivo) {
    ofstream file(nombreArchivo);
    for (const auto& persona : tabla.obtenerTodos()) {
        file << persona.toString() << endl;
    }
}

// Funciones CRUD
void crearPersona(TableHash& tabla) {
    Persona nuevaPersona;
    cout << "Ingrese el nombre: ";
    cin >> nuevaPersona.nombre;
    cout << "Ingrese la edad: ";
    cin >> nuevaPersona.edad;
    cout << "Ingrese la carrera: "; 
    cin >> nuevaPersona.carrera;
    cout << "Ingrese el ID: ";
    cin >> nuevaPersona.id;
    tabla.insertar(nuevaPersona);
    cout << "Persona agregada correctamente." << endl;
}

void leerPersona(TableHash& tabla) {
    string id;
    cout << "Ingrese el ID de la persona a buscar: ";
    cin >> id;
    Persona persona;
    if (tabla.buscar(id, persona)) {
        cout << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << ", Carrera: " << persona.carrera << endl;
    } else {
        cout << "Persona no encontrada." << endl;
    }
}

void actualizarPersona(TableHash& tabla) {
    string id;
    cout << "Ingrese el ID de la persona a actualizar: ";
    cin >> id;
    Persona persona;
    if (tabla.buscar(id, persona)) {
        cout << "Ingrese el nuevo nombre: ";
        cin >> persona.nombre;
        cout << "Ingrese la nueva edad: ";
        cin >> persona.edad;
        cout << "Ingrese la nueva carrera: ";
        cin >> persona.carrera;
        tabla.eliminar(id); // Eliminar la entrada antigua
        tabla.insertar(persona); // Insertar la nueva entrada
        cout << "Persona actualizada correctamente." << endl;
    } else {
        cout << "Persona no encontrada." << endl;
    }
}

void eliminarPersona(TableHash& tabla) {
    string id;
    cout << "Ingrese el ID de la persona a eliminar: ";
    cin >> id;
    tabla.eliminar(id);
    cout << "Persona eliminada correctamente." << endl;
}

void verTodasLasPersonas(const TableHash& tabla) {
    vector<Persona> personas = tabla.obtenerTodos();
    if (personas.empty()) {
        cout << "Datos vacíos." << endl;
    } else {
        cout << "Lista de personas:" << endl;
        for (const auto& persona : personas) {
            cout << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << ", Carrera: " << persona.carrera << ", ID: " << persona.id << endl;
        }
    }
}

void mostrarMenu() {
    cout << "Menu de opciones:" << '\n';
    cout << "1. Crear Persona" << '\n';
    cout << "2. Leer Persona" << '\n';
    cout << "3. Actualizar Persona" << '\n';
    cout << "4. Eliminar Persona" << '\n';
    cout << "5. Ver Todas las Personas" << '\n'; 
    cout << "6. Salir" << '\n';
}

int main() {
    TableHash tabla(10); // Tamaño de la tabla hash
    const string nombreArchivo = "personas.txt";

    // Cargar datos iniciales del archivo
    cargarDatos(tabla, nombreArchivo);

    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearPersona(tabla);
                break;
            case 2:
                leerPersona(tabla);
                break;
            case 3:
                actualizarPersona(tabla);
                break;
            case 4:
                eliminarPersona(tabla);
                break;
            case 5:
                verTodasLasPersonas(tabla); // Llamar a la nueva función
                break;
            case 6:
                guardarDatos(tabla, nombreArchivo); // Guardar cambios en el archivo
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0; // Fin del programa
}