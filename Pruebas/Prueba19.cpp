/*
/*
/*
Pregunta 2: Agregar Nuevos Registros de Estudiantes

Tienes un archivo secuencial llamado "estudiantes.dat" que contiene información de estudiantes. Cada estudiante tiene los siguientes atributos:

Nombre (cadena de caracteres)
ID (entero)
Carrera (cadena de caracteres)
Escribe un programa en C++ que permita al usuario agregar nuevos registros de estudiantes al final del archivo "estudiantes.dat". 
El programa debe solicitar al usuario la información de cada nuevo estudiante y luego agregarla al archivo.

Consideraciones Adicionales:

Asegúrate de manejar adecuadamente los errores, como archivos no encontrados o entradas inválidas.
Utiliza funciones para modularizar tu código y hacerlo más legible.
En ambos ejercicios, es importante que el alumno contemple el uso de la libreria fstream para la manipulación de archivos.
Se recomienda que el alumno utilize estructuras para el manejo de los datos de cada registro.*/


#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

struct Estudiante {
    char nombre[100]; 
    char carrera[100]; 
    int id;           

    const char* get_nombre() const {
        return nombre;
    }

    void set_nombre(const char* nombre) {
        strncpy(this->nombre, nombre, sizeof(this->nombre) - 1);
        this->nombre[sizeof(this->nombre) - 1] = '\0';
    }

    const char* get_carrera() const {
        return carrera;
    }

    void set_carrera(const char* carrera) {
        strncpy(this->carrera, carrera, sizeof(this->carrera) - 1);
        this->carrera[sizeof(this->carrera) - 1] = '\0'; 
    }

    int get_id() const {
        return id;
    }

    void set_id(int id) {
        if (id <= 0) {
            throw invalid_argument("ERROR: valor ingresado inválido");
        }
        this->id = id;
    }
};

void agregar_estudiante(const Estudiante* n) {
    ofstream Guardar("estudiantes.dat", ios::binary | ios::app);
    if (!Guardar) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    Guardar.write(reinterpret_cast<const char*>(n), sizeof(Estudiante));
    Guardar.close();
}

Estudiante encontrar_estudiante(int id) {
    ifstream leer("estudiantes.dat", ios::binary);
    if (!leer) {
        cerr << "Error al abrir el archivo para lectura" << endl;
        exit(1);
    }

    Estudiante estudiante;
    while (leer.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        if (estudiante.id == id) {
            leer.close();
            return estudiante;
        }
    }
    leer.close();
    throw runtime_error("Estudiante no encontrado");
}

void modificar_carrera(int id, const char* nueva_carrera) {
    fstream modificar("estudiantes.dat", ios::binary | ios::in | ios::out);
    if (!modificar) {
        cerr << "Error al abrir el archivo para modificar" << endl;
        return;
    }

    Estudiante estudiante;
    bool encontrado = false;

    while (modificar.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        if (estudiante.id == id) {
            estudiante.set_carrera(nueva_carrera);

            modificar.seekp(-static_cast<int>(sizeof(Estudiante)), ios::cur);
            modificar.write(reinterpret_cast<const char*>(&estudiante), sizeof(Estudiante));
            encontrado = true;
            break;
        }
    }

    modificar.close();
    if (!encontrado) {
        throw runtime_error("Estudiante no encontrado para modificar la carrera");
    }
}

int main() {
    char continuar;
    do {
        Estudiante estudiante;
        cout << "Ingrese el nombre del estudiante: ";
        cin.ignore();
        cin.getline(estudiante.nombre, 100);

        cout << "Ingrese el ID del estudiante: ";
        cin >> estudiante.id;

        cout << "Ingrese la carrera del estudiante: ";
        cin.ignore();
        cin.getline(estudiante.carrera, 100);

        agregar_estudiante(&estudiante);
        cout << "Estudiante agregado exitosamente." << endl;

        cout << "¿Desea agregar otro estudiante? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    int id_busqueda;
    char nueva_carrera[100];
    cout << "Ingrese el ID del estudiante cuya carrera desea modificar: ";
    cin >> id_busqueda;
    cout << "Ingrese la nueva carrera: ";
    cin.ignore();
    cin.getline(nueva_carrera, 100);

    try {
        modificar_carrera(id_busqueda, nueva_carrera);
        cout << "Carrera modificada exitosamente." << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << "Programa finalizado." << endl;
    return 0;
}