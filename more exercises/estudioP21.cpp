#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
// CREAR EL ARCHIVO
// ofstream carlos("pruebaDeAbrirYLectura.txt");
// carlos << "Probando crear y abrir" << endl;
// carlos << "Veamos como sale" << endl;
// carlos.close();


// // //ABRIR Y LEER ARCHIVO
// ifstream juan("pruebaDeAbrirYLectura.txt");
// string paraLeer;

// if(!juan.is_open()){
//     cerr << "No se pudo abrir el archivo" << endl;
//     return 0;
// } else {
//     while(getline(juan,paraLeer)){
//         cout << paraLeer << endl;
//     }
//     juan.close();
// }

//ESCRIBIR DE NUEVO
// ofstream pedro("pruebaDeAbrirYLectura.txt",ios::app);
// if(!pedro.is_open()){
//     cerr << "No se pudo abrir el archivo" << endl;
//     return 1;
// } else {
//     pedro << "Probando si se sobre escribio" << endl;
//     pedro.close();
// }

fstream julio("pruebaDeAbrirYLectura.txt" , ios::app | ios::in | ios::out );

string paraReleer;

if(!julio.is_open()){
    cerr << "No se pudo abrir el archivo" << endl;
    return 0;
} else {
    while(getline(julio,paraReleer)){
        cout << paraReleer <<endl;
    }
    julio.clear();
    julio.seekg(0);
    

    julio << "AGREGANDO ESTO: Probando si se sobre escribio" << endl;
    julio << "Vamos de nuevo... " << endl;

    julio.seekg(0);



    while(getline(julio,paraReleer)){
        cout << paraReleer <<endl;
    }
    julio.close();
}
return 0;

}
