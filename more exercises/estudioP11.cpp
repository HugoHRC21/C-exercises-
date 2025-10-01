/*Objetivo: Crear una estructura llamada CadenaDeCaracteres que almacene una cadena de caracteres y permita realizar operaciones básicas sobre ella.

Enunciado:
Definición de la Estructura:
Implementa la estructura CadenaDeCaracteres, que debe contener:
Un array de caracteres de tamaño fijo (por ejemplo, 100) para almacenar la cadena.
Un entero que represente la longitud actual de la cadena (sin contar el carácter nulo).
Funciones de la Estructura:
Implementa las siguientes funciones:
void inicializar(const char* cadena): Inicializa la estructura con la cadena proporcionada.
void imprimir(): Imprime la cadena almacenada.
int longitud(): Devuelve la longitud actual de la cadena.
void concatenar(const char* cadena): Agrega una nueva cadena al final de la cadena existente en la estructura (asegúrate de no exceder el tamaño del array).
Función Principal:
En la función main, crea una instancia de CadenaDeCaracteres.
Utiliza las funciones implementadas para:
Inicializar la cadena con un valor dado.
Imprimir la cadena.
Mostrar la longitud de la cadena.
Concatenar otra cadena y volver a imprimir la cadena resultante.

Consideraciones:
Asegúrate de manejar correctamente el carácter nulo (\0) al final de la cadena.
Si la longitud total de la cadena concatenada excede el tamaño máximo del array, corta la cadena adicional para evitar desbordamientos.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct CadenaDeCaracteres{
    char cadena[100];
    int longitud;

    void inicializar(const char* entrada){
        char* destino = cadena;
        const char* fuente = entrada;

        while(*fuente != '\0'){
            *destino = *fuente;
            fuente++;
            destino++;
        }
        *destino='\0';
        longitud = strlen(cadena);
    }

    char* imprimir(){
        return cadena;
    }
    int obtenerlongitud(){
        return longitud;
    }

};


int main(){
    CadenaDeCaracteres cadena1;
    const char* inicial = "hellopeople";

    cadena1.inicializar(inicial);

    cout << "la cadena es:  " << cadena1.imprimir() <<endl;

    cout << "longitud de la cadena:  " << cadena1.obtenerlongitud() <<endl;



    return 0;
}

