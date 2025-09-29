#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void escribir(){
    ofstream archivo;
    string nombreArchivo, frase;

    cout<< "ingrese el mugroso nombre del archivo jejje porfavor" << endl;
    getline(cin,nombreArchivo);

    archivo.open(nombreArchivo.c_str(), ios::out);

    if(archivo.fail()){
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    cout << "\nDigite el texto del archivo: ";
    getline(cin,frase);

    archivo << frase;

    archivo.close();     

};

int main(){
    escribir();
     
    return 0;

}
