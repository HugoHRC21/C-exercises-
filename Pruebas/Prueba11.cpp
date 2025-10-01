/*Ejercicio 4: Herencia y Memoria Dinámica 
Crea una clase base Persona con: 
Nombre (cadena). 
Edad (int). 
Método mostrarDatos(). 
Crea una clase Profesor que herede de Persona y agregue: 
Materia que enseña (cadena). 
Método mostrar Datos() que muestre también la materia. 
En el main, crea un objeto Profesor, inicialízalo dinámicamente con new, muestra sus datos y libera la memoria con delete.*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class person {
    private:
        string name;
        int age;
    public:
        person(string n, int a) : name(n) {
            this -> setAge(a);
        }

        void setAge(int a ) {
            if (a < 0) throw invalid_argument("Age must be non-negative");

            this -> age = a;
        }

        virtual void showInfo(){
            cout << "Person information: " << endl;
            cout << "Name: " << name << ", Age: " << age;
        }
};
class teacher:public person{
    private:
        string subject;
    public:
        teacher(string n, int a, string s) : person(n,a), subject(s) {}
        
        void showInfo() override {
            person:: showInfo();
            cout <<", Subject taught: " << subject << endl;
        }
};

int main(){
    teacher* julio = new teacher("julio lugo", -28, "Programming");
    julio->showInfo();
    delete julio;

    return 0;

}