#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Persona{
    protected:
        string nombre;
        int edad;
    public:
        Persona(){
            this->setNombre("s/n");
            this->setEdad(0);
        }
        Persona(string nombre, int edad){
            this->setNombre(nombre);
            this->setEdad(edad);
        }

        virtual string getNombre(){
            return this->nombre;
        }
        virtual int getEdad(){
            return this->edad;
        }
        virtual void setNombre(string nombre){
            this->nombre = nombre;
        }
        virtual void setEdad(int edad){
            this->edad = edad;
        }

        virtual void mostrarinformacion(ostream& out){
            out << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
};

class Estudiante : public Persona{
    private:
        string carrera;
        int semestre;
    public:
        Estudiante(string nombre, int edad, string carrera, int semestre) : Persona(nombre, edad){
            this->setCarrera(carrera); 
            this->setSemestre(semestre);
        }

        string getCarrera(){
            return this->carrera;
        }
        int getSemestre(){
            return this->semestre;
        }

        void setCarrera (string carrera){
            this->carrera = carrera;
        }
        void setSemestre (int carrera){
            this->semestre = semestre;
        }

        void mostrarinformacion(ostream& out) override {
            out << "Nombre: " << nombre << ", Edad: " << edad << ", Carrera: " << carrera << endl;
        };
};

 
int main(){
    Persona* personas1 = new Persona ("carlos",24);

    Estudiante* estudiante1 = new Estudiante ("Roberto", 25, "Psicologia", 5);
 
    personas1->mostrarinformacion(cout);
    estudiante1->mostrarinformacion(cout);

    ofstream archivoNew ("TextoCrack.txt");
    if(archivoNew.is_open()){
        archivoNew << "Información de la Persona: " << '\n';
        personas1->mostrarinformacion(archivoNew);
        archivoNew << "Información del estudiante: " << '\n';
        estudiante1->mostrarinformacion(archivoNew); 
        archivoNew.close();
        cout << "Información guardada bien-excelente" << '\n';
    } else {
        cerr << "No funciono esta monda" << endl;
    }

    delete personas1;
    delete estudiante1;
 


    return 0;

}
