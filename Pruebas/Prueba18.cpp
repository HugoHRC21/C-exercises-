/*CRUD de Libros

Diseña un programa en C++ que implemente un sistema CRUD (Crear, Leer, Actualizar, Eliminar) para una biblioteca. 
El programa debe utilizar un archivo secuencial llamado "libros.dat" para almacenar la información de los libros. 
Cada libro debe tener los siguientes atributos:

Título (cadena de caracteres)
Autor (cadena de caracteres)
ISBN (entero)
Año de publicación (entero)
El programa debe proporcionar las siguientes funcionalidades:

Crear: Permitir al usuario agregar nuevos libros al archivo.
Leer: Permitir al usuario buscar y mostrar la información de un libro por su ISBN.
Actualizar: Permitir al usuario modificar la información de un libro existente por su ISBN.
Eliminar: Permitir al usuario eliminar un libro del archivo por su ISBN.*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

struct Libro {
    char nombre[100]; 
    char autor[100];  
    int ISBN;       
    int Ano;         

    const char* get_nombre() const {
        return nombre;
    }

    void set_nombre(const char* new_nombre) {
        strncpy(nombre, new_nombre, sizeof(nombre) - 1);
        nombre[sizeof(nombre) - 1] = '\0'; 
    }

    const char* get_autor() const {
        return autor;
    }

    void set_autor(const char* new_autor) {
        strncpy(autor, new_autor, sizeof(autor) - 1);
        autor[sizeof(autor) - 1] = '\0';
    }

    int get_ISBN() const {
        return ISBN;
    }

    void set_ISBN(int new_ISBN) {
        if (new_ISBN <= 0) {
            throw invalid_argument("ERROR: ISBN inválido");
        }
        ISBN = new_ISBN;
    }

    int get_Ano() const {
        return Ano;
    }

    void set_Ano(int new_Ano) {
        if (new_Ano < 0 || new_Ano > 2025) {
            throw invalid_argument("ERROR: Año inválido");
        }
        Ano = new_Ano;
    }
};

void agregar_libro(const Libro* l){
    ofstream agregar("Libros.dat", ios::binary | ios::out | ios::app);
    if(!agregar){
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }
    agregar.write(reinterpret_cast<const char*>(l), sizeof(Libro));
    agregar.close();    
};

Libro leer_libro(int ISBN){
    ifstream leer("Libros.dat", ios:: binary | ios:: in);
    if(!leer){
        cerr << "Error al abrir el archivo para leer" << endl;
        exit(1);
    }

    Libro libroleer;
    while(leer.read(reinterpret_cast<char*>(&libroleer), sizeof(Libro))){
        if(libroleer.ISBN == ISBN){
            leer.close();
            return libroleer;
        }
    }
    leer.close();
    throw runtime_error("Libro no encontrado");
};

void modificar_libro(int ISBN){
    fstream modificar("Libros.dat", ios::binary | ios::in | ios::out);
    if(!modificar){
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }
    Libro libroM;
    bool encontrado = false;

    while (modificar.read(reinterpret_cast<char*>(&libroM), sizeof(Libro))){
        if(libroM.ISBN == ISBN){

            cout << "Ingrese el Nuevo titulo del Libro: " << endl;
            cin.ignore();
            cin.getline(libroM.nombre, 100);

            cout << "Ingrese el Autor titulo del Libro: " << endl;
            cin.getline(libroM.autor, 100);


            int nuevo_ano;
            cout << "Ingrese el Ano de publicacion Libro" << endl;
            cin >> nuevo_ano;

            try {
                libroM.set_Ano(nuevo_ano); 
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                modificar.close();
                return; 
            }

            modificar.seekp(-static_cast<int>(sizeof(Libro)), ios::cur);
            modificar.write(reinterpret_cast<const char*>(&libroM), sizeof(Libro));
            encontrado = true;
            break;
        }
    }

    modificar.close();
    if(!encontrado){
        throw runtime_error("Libro no encontrado para modificarlo");
    }
};

void eliminar_libro(int ISBN){
    ifstream leer("libros.dat", ios::binary | ios::in);
        if (!leer) {
            cerr << "Error al abrir el archivo para leer" << endl;
            return;
        }
    
    ofstream temporal("temporal.dat", ios::binary | ios:: out);
    Libro libro;
        
    while (leer.read(reinterpret_cast<char*>(&libro), sizeof(Libro))) {
       if (libro.ISBN != ISBN) {
            temporal.write(reinterpret_cast<const char*>(&libro), sizeof(Libro));
        }
    }
    leer.close();
    temporal.close();
  
    remove("libros.dat");
    rename("temporal.dat", "libros.dat");
    

};

int main(){
    int opcion;

    do{
        cout << "Menu:" << endl; 
        cout << "1. Crear Nuevo Libro" << endl;
        cout << "2. Buscar un Libro" << endl;
        cout << "3. Modificar un libro" << endl;
        cout << "4. Eliminar un libro" << endl;
        cout << "5.Salir " << endl;
        cin >> opcion;

        switch (opcion){
        case 1: {
            Libro nuevo_libro;
            cout << "Ingrese el título del libro: ";
            cin.ignore();
            cin.getline(nuevo_libro.nombre, 100);
            cout << "Ingrese el autor: ";
            cin.getline(nuevo_libro.autor, 100);
            cout << "Ingrese el ISBN: ";
            cin >> nuevo_libro.ISBN;
            cout << "Ingrese el año de publicación: ";
            cin >> nuevo_libro.Ano;
            agregar_libro(&nuevo_libro);
            cout << "Libro agregado exitosamente." << endl;
            break;

            break;}
        case 2:{
            int ISBN;
            cout << "Ingrese el ISBN del libro a buscar: ";
            cin >> ISBN;
            try {
                Libro libro = leer_libro(ISBN);
                cout << "Título: " << libro.nombre << ", Autor: " << libro.autor 
                     << ", ISBN: " << libro.ISBN << ", Año: " << libro.Ano << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;}
        case 3:{
            int ISBN;
            cout << "Ingrese el ISBN del libro a modificar: ";
            cin >> ISBN;
            cin.ignore();
            try {
                modificar_libro(ISBN);
                cout << "Libro modificado exitosamente." << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
            }
        case 4:{
            int ISBN;
            cout << "Ingrese el ISBN del libro a eliminar: ";
            cin >> ISBN;
            eliminar_libro(ISBN);
            cout << "Libro eliminado exitosamente." << endl;
            break;
         }
        case 5:{
            cout << "Saliendo del programa." << endl;
            break;}
        
        default:
            cout << " Valor ingresado invalido, Intentelo de nuevo" << endl;
        }

}while(opcion !=5);

   return 0;
}