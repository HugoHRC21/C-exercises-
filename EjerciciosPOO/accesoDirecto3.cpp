#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    char letra;
    fstream letras("coyote.txt", ios::in|ios::out);

    if(!letras){
        cerr << "Error al abrir el archivo" << endl;
    }

    letras.seekg(7,ios::beg);
    letra=letras.get();
    letras.seekp(0,ios::end);
    letras << letra;

    letras.seekg(14,ios::beg);
    letra = letras.get();
    letras.seekp(0,ios::end);
    letras << letra;

    letras.seekg(11,ios::beg);
    letra=letras.get();
    letras.seekp(0,ios::end);
    letras << letra;

    letras.seekg(0,ios::beg);
    letra=letras.get();
    letras.seekp(0,ios::end);
    letras << letra;

    letras.seekg(-4,ios::end);
    while (!letras.eof()){
      cout.put((char)letras.get());
    }

    letras.close();    
    return 0;
};