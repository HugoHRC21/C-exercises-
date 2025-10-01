#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>


using namespace std;

#include <fstream>
#include <iostream>
#include <sstream>

const int TAMANO_ARRAY = 5;

void escribirNumeros(const int numeros[], int tamaño) {
    ofstream outFile("numeros.txt");

    if (!outFile) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    for (int i = 0; i < tamaño; ++i) {
        outFile << numeros[i] << endl; 
    }

    outFile.close();
}

int leerNumeroEnPosicion(int posicion) {
    ifstream inFile("numeros.txt");
    string linea;
    int numero = 0;

    if (!inFile) {
        cerr << "Error al abrir el archivo para leer." << std::endl;
        return -1; 
    }

    for (int i = 0; i <= posicion; ++i) {
        if (getline(inFile, linea)) {
            if (i == posicion) {
                stringstream(linea) >> numero; 
            }
        } else {
            cerr << "Posición fuera de rango." << std::endl;
            return -1; 
        }
    }

    inFile.close();
    return numero;
}

int main() {
    int numeros[TAMANO_ARRAY] = {10, 20, 30, 40, 50};

    escribirNumeros(numeros, TAMANO_ARRAY);

    int posicion = 4; 
    int numeroLeido = leerNumeroEnPosicion(posicion);

    if (numeroLeido != -1) {
        cout << "Número leído en posición " << posicion << ": " << numeroLeido << std::endl;
    }

    return 0;
}