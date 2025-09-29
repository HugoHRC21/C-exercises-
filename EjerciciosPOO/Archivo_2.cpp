#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void lectura(){
    ifstream archivo2;
    string texto; 

    archivo2.open("Psicologia.txt",ios::in);
    
    if(archivo2.fail()){
        cerr << "nose pudo abrir esta joda jeje" <<endl;
        exit(1);
    }

    while(!archivo2.eof()){
        getline(archivo2,texto);
        cout << texto << endl;
    }
    archivo2.close();
    
};

int main(){
    lectura();
    

    return 0;

}
