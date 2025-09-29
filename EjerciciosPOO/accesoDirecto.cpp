#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

struct Registro {
    int id;
    char nombre[50];
};

int main(){
    int opcion;
    ofstream outputfile("registro.txt", ios::binary);

    for (int i = 1; i <=5 ; ++i){
        Registro reg;
        reg.id = i;
        snprintf(reg.nombre, sizeof(reg.nombre), "hola %d",i);
        outputfile.write(reinterpret_cast<char*>(&reg), sizeof(Registro));        
    }
    outputfile.close();

    ifstream inputfile("registro.txt", ios::binary);
    cout << "Ingrese el numero de registro que desea conocer: " << '\n';
    cin >> opcion;
     
    inputfile.seekg(opcion * sizeof(Registro));
    Registro reg;
    inputfile.read(reinterpret_cast<char*>(&reg), sizeof(Registro));

    cout<< "Registro Leido: ID = " << reg.id << " , Nombre = " << reg.nombre << endl;
     
    inputfile.close();    

    return 0;

}
