#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_NAME_LENGTH 20

struct  Estudiante{
    int id;
    char nombre[20];
    float calificacion;

    void set_id(int i){
        if(i <= 0) throw invalid_argument("Iid invalido");
        this -> id = i;
    }
    void set_calificaion(int c){
        if(c <= 0 or c > 20.00) throw invalid_argument("Calificaion invalida");
        this -> calificacion = c;
    }

    void set_nombre(const char* n){
        if(strlen(n) > MAX_NAME_LENGTH) {throw length_error("Name length is longer than expected");}
        
        strncpy(this->nombre, n, strlen(n));
    }

};

int main(){
    Estudiante Hugo;
    size_t tamano = sizeof(Hugo);
    cout << "El tamano del archivo es de: " << tamano << "bytes." <<endl;
    return 0;
}

