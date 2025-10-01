#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>


using namespace std;

# define MAX_NAME_LENGTH 20

struct  Estudiante{
    int id;
    char nombre[MAX_NAME_LENGTH];
    float calificacion;

    void set_id(int i){
        if(i <= 0) throw invalid_argument("Id invalido");
        this -> id = i;
    }
    void set_calification(float c){
        if(c <= 0 or c > 20.00) throw invalid_argument("Calificaion invalida");
        this -> calificacion = c;
    }
    void set_nombre (const char* n){
        if(strlen(n) > MAX_NAME_LENGTH) {throw length_error("Name length is longer than expected");}

        strncpy(this-> nombre, n, strlen(n));
    }

};

void agregar_estudiante(const Estudiante* n){  
    ofstream Guardar("estudiantes.dat", ios::out | ios::binary | ios::app);
     if(!Guardar){
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
     } 
     Guardar.write(reinterpret_cast<const char*>(&n), sizeof(Estudiante));
     Guardar.close();

};

Estudiante leer_registro(int indice){
    ifstream leer("estudiantes.dat", ios::binary | ios::in);
    if(!leer){
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    Estudiante estuLeer;
    long posicion = indice * sizeof(Estudiante);
    leer.seekg(posicion);
    leer.read(reinterpret_cast<char*>(&estuLeer), sizeof(Estudiante));
    return estuLeer;
};

Estudiante EncontrarPersona_ID(int id){
    ifstream leer("estudiantes.dat", ios::binary | ios::in);
    if(!leer){
        cerr << "Error al abrir el archivo para lectura" << endl;
        exit(1);
    }
    
    Estudiante estudID;
    while(leer.read(reinterpret_cast<char*>(&estudID), sizeof(estudID))){
        if(estudID.id == id){
            leer.close();
            return estudID;
        }
    }
    leer.close();
    throw runtime_error("Estudiante no encotrado");
};

Estudiante EncontrarPersona_Nombre(const char* nombre){
    ifstream leer("estudaintes.dat", ios::binary);
    if(!leer){
        cerr << "Erro al abrir el archivo para lectura" << endl;
        exit(1);
    }
    Estudiante estuNombre;
    while(leer.read(reinterpret_cast<char*>(&estuNombre), sizeof(estuNombre))){
        if(estuNombre.nombre == nombre){
            leer.close();
            return estuNombre;
        }
    }
    leer.close();
    throw runtime_error("Persona no encontrada");
};

int Person_cantidad(){
    ifstream calcu("estudiantes.dat", ios::binary);
    if(!calcu){
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }
    calcu.seekg(0, ios::end);
    int cantidad = calcu.tellg() / sizeof(Estudiante);
    calcu.close();
    return cantidad;
};


void insertar_Estudiante(int posicion, const Estudiante* nuevo_estudiante){
    ifstream lectura ("estudiantes.dat", ios::binary);
    if(!lectura){
        cerr << "error al abrir el archivo" << endl;
        return;
    }
    lectura.seekg(0, ios::end);
    int cantidad = lectura.tellg() / sizeof(Estudiante);
    lectura.seekg(0, ios::beg);


    Estudiante* estudiantes = new Estudiante[cantidad+1];
    lectura.read(reinterpret_cast<char*>(&estudiantes), cantidad * sizeof(Estudiante));
    lectura.close();

    for(int i = cantidad; i > posicion; i--){
        estudiantes[i] = estudiantes[i-1];
    }

    estudiantes[posicion] = *nuevo_estudiante;

    ofstream escribir("estudiantes.dat", ios::out | ios::binary);
    escribir.write(reinterpret_cast<char*>(estudiantes), (cantidad +1)*sizeof(Estudiante));
    escribir.close();

    delete[] estudiantes;
};



int main(){    
    int t,indice, ID;
    char Nombre[MAX_NAME_LENGTH];
    cout << "Ingrese el numero de Estudiantes a crear:  "; cin >> t; cout << endl;
    
    Estudiante* estudiantes = new Estudiante[t];

        for(int i = 0; i < t; i++){
        int id = 0;
        float calif = 0.0;
        char nombre[MAX_NAME_LENGTH];
       
        cout << "Ingrese los datos del Estudiante " << i+1 << ": " << endl;
        cout << "ingrese Nombre: "; 
        cin >> nombre; estudiantes[i].set_nombre(nombre);
        cout << "ingrese ID: "; cin >> id; estudiantes[i].set_id(id);
        cout << "ingrese Calificacion: "; cin >> calif; estudiantes[i].set_calification(calif);
        cout << "------------------------------------" << endl;
        
        agregar_estudiante(&estudiantes[i]);
        }
        cout << "Registros guardados exitosamente en el archivo 'estudiantes.dat' " << endl;

        cout << "El numero de estudiantes guardados es de: " << Person_cantidad() << endl;

        cout << "Ingrese el indice correspondiente al estudiante que desea ver: "; cin >> indice; 
        if(indice < 0 || indice > Person_cantidad()) {
            cerr << " * Indice fuera del rango de valores *" <<endl;
            return -1;}
        indice = indice -1;

        estudiantes[indice] = leer_registro(indice);
        cout << "Nombre: " << estudiantes[indice].nombre << endl;
        cout << "ID: " << estudiantes[indice].id << endl;
        cout << "Calificacion: " << estudiantes[indice].calificacion << endl;


        cout << "Ingrese el ID del estudiante que desea consultar: ", cin >> ID;
        try {
            Estudiante estuID = EncontrarPersona_ID(ID);
            cout << "Nombre: " << estuID.nombre << endl;
            cout << "Id: " << estuID.id << endl;
            cout << "Calificacion: " << estuID.calificacion << endl;
        } catch (runtime_error e){
            cerr << e.what() << endl;
        }

        cout << "Ingrese el Nombre de la persona que desea consultar: "; cin >> Nombre; 
        try{
            Estudiante estuNombre = EncontrarPersona_Nombre(Nombre);
            cout << "Nombre: " << estuNombre.nombre << endl;
            cout << "Id: " << estuNombre.id << endl;
            cout << "Calificacion: " << estuNombre.calificacion << endl;
        } catch(runtime_error e){
            cerr << e.what() << endl;
        }

        delete[] estudiantes;
    
    return 0;
}

