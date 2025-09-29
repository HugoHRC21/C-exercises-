#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void aniadir(){
    ofstream archivo3;
    string texto;

    archivo3.open("Psicologia.txt", ios::app);

    if(archivo3.fail()){
        cerr << "No se abrio esa monda" << endl;
        exit(1);
    }

    cout << "agrege alguna monda que usted quiera al texot" << endl;
    getline(cin,texto);
    
    archivo3 << texto << endl;

    archivo3.close();

};

int main(){
    aniadir();
    

    return 0;

}
