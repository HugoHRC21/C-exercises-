/*Ejercicio 1: Sistema de Gestión de Empleados 
Implementa un sistema para gestionar empleados usando herencia y memoria dinámica. 
Requisitos: 
1. Crea una clase base Empleado con: 
* Nombre (dinámico). 
* Edad. 
* Salario base. 
Método virtual calcularSalario() (devuelve el salario base). 
* Destructor adecuado para liberar memoria. 
2. Crea dos clases derivadas: 
Gerente: recibe un bono adicional (float). Su salario es salario base + bono. 
Vendedor: recibe comisiones (float) y su salario es salario base + comisiones. 
3. Usa un vector de punteros a Empleado para manejar diferentes empleados en el main. 
4. Permite agregar empleados dinámicamente y calcular sus salarios. 
5. Asegúrate de liberar correctamente la memoria antes de salir.*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class employee{
    private:
        char* name;
        int age;
        float salary;
    public:

    employee(char* n, int a, float s) {
        this->name = new char[100];
        int i = 0;

        while (name[i] != '\0') {
            this->name[i] = name[i];
            i++;
        }
        this->name[i] = '\0';
        this->set_age(a);
        this->set_salary(s);
    }
 
  void set_age(int a){
        if(a <= 0 or a > 100) throw invalid_argument("invalid entered age");
        this -> age= a;
    }
    int get_age(){
        return this->age;
    }
    void set_salary(float s){
        if (s < 0.0) throw invalid_argument("invalid amount");
        this -> salary = s;
    }
    float get_salary(){
        return this->salary;
    }

    ~employee(){
        delete[] name;
    }

    virtual void calculate_salary (){
        cout << "The Employee's Salary " << this->name << " is from: " << get_salary();
    }
};


class manager: public employee {
    private:
        float bond;
    public: 
        manager(char* n, int a, float s, float b) : employee(n,a,s){
            this-> set_bond(b);
        }
        void set_bond(float b){
            if (b < 0.0) throw invalid_argument("invalid bonus amount");
            this -> bond = b;
        }
        float get_bond(){
            return this -> bond;
        }

        void calculate_salary() override {
            employee::calculate_salary();
            cout << " - management bonus: " << get_bond() << endl;
            cout << "Final salary: " << get_salary() + get_bond() << "\n" << endl;
        }

};

class seller: public employee {
    private:
        float bondS;
    public: 
        seller(char* n, int a, float s, float b) : employee(n,a,s){
            this-> set_bondS(b);
        }
        void set_bondS(float b){
            if (b < 0.0) throw invalid_argument("invalid bonus amount");
            this -> bondS = b;
        }
        float get_bondS(){
            return this -> bondS;
        }

        void calculate_salary() override {
            employee::calculate_salary();
            cout << " - sales commission: " << get_bondS() << endl;
            cout << "Final salary: " << get_salary() + get_bondS() << "\n" << endl;
        }

};



int main(){

    int n;
    cout << "Enter the number of elements: ";
    cin >> n; cout << "\n"; 

    employee** Employees = new employee*[n];

    for(int i = 0; i < n; i++){
        char name[100];
        int age;
        float salary;
        float bond;

        
        cout << "enter the name of employee number " << i+1 << ": ";
        cin >> name;
        cout << "enter the age of employee number " << i+1 << ": ";
        cin >> age;
        cout << "enter the avarage of employee number " << i+1 << ": ";
        cin >> salary;

        cout << "Is this employee a manager (1) or a seller (2)? ";
        int type;
        cin >> type;

        if (type == 1) {
            float bond;
            cout << "Enter the management bonus: ";
            cin >> bond;
            Employees[i] = new manager(name, age, salary, bond);
        } else {
            float commission;
            cout << "Enter the sales commission: ";
            cin >> commission;
            Employees[i] = new seller(name, age, salary, commission);
        }
        cout << "\n";
    }
        for (int i = 0; i < n; i++){
            Employees[i]->calculate_salary();
        }

        for(int i =0 ; i < n; i++){
            delete Employees[i];
        }

        delete[] Employees;
        


    return 0;
}

