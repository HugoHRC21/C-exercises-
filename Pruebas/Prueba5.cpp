/*Ejercicio 1: Estructuras de Datos 
Implementa una estructura de datos para gestionar una biblioteca. La biblioteca puede almacenar 
hasta 100 libros, cada uno con la siguiente información: 
ID del libro (número entero) 
Título (cadena de texto) 
Autor (cadena de texto) 
Año de publicación (entero) 
Estado (disponible o prestado) 
Requisitos: 
1. Crea una estructura (struct o clase, según el lenguaje). 
2. Implementa funciones para: 
Agregar un nuevo libro. 
Buscar un libro por título y mostrar su información. 
Marcar un libro como prestado o disponible. 
3. Usa un arreglo o lista para almacenar los libros. 
4. Prueba tu código con al menos 3 libros y muestra su información en pantalla*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maximo = 5;
struct book{
    int ID; 
    string titulo; 
    string autor;
    int Ano;
    bool Estado;

    void agregarLibro(book book[], int &contador, int ID, string titulo, string autor, int ano){
        if(contador < maximo){
            book[contador] = {ID, titulo, autor, ano, true};
            contador++;
            cout << "Libro agregador: " << titulo << endl; 
        } else  {
            cout << "No se pudo agregar el libro, capacidad maxima alcanzada de almacenaje" << "\n" << endl;
        }
    }

    void buscarLibro(book book[], int contador,string titulo){
        for (int i = 0; i < contador; i++){
            if (titulo == book[i].titulo){
                cout << "Libro encontrado!" << endl;
                cout << "ID: " << book[i].ID << endl; 
                cout << "Titulo: " << book[i].titulo << endl; 
                cout << "Autor: " << book[i].autor << endl; 
                cout << "Ano: " << book[i].Ano << endl; 
                cout << "Estado: " << book[i].Estado << "\n" <<  endl; 
                return;
            }
        }
        cout << "Libro no encontrado" << endl;
    }

    void MarcarLibro(book book[], int contador, int ID){
        for(int i = 0; i < contador; i++){
            if(book[i].ID == ID){
                book[i].Estado = !book[i].Estado;
                cout << "Estado del Libro Actulizado: " << book[i].titulo << " - Estado: " << book[i].Estado << endl; 
            } 
        }
    }

};


int main(){

    book Estante [maximo];
    int contador = 0;

    Estante->agregarLibro(Estante, contador, 1,"Hugo el loco", "Hugo rivas", 2024 );
    Estante->agregarLibro(Estante, contador, 3,"La historia", "Rafae", 2023);
    Estante->agregarLibro(Estante, contador, 2, "La trayectoria", "Julio", 2053);


    Estante->buscarLibro(Estante, contador, "Hugo el loco"); 
    Estante->buscarLibro(Estante, contador, "La historia"); 
    Estante->buscarLibro(Estante, contador, "La trayectoria"); 
 

    Estante->MarcarLibro(Estante, contador, 2);

 
    Estante->buscarLibro(Estante, contador, "Hugo el loco"); 
    Estante->buscarLibro(Estante, contador, "La historia"); 
    Estante->buscarLibro(Estante, contador, "La trayectoria"); 



    return 0;
}