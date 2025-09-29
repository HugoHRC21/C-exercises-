#include<iostream>
#include<string>
#include <fstream>
using namespace std;

class Vehiculo {
    protected:
        string marca;
        string modelo;
        int ano; 
    public:
        Vehiculo(){
            this->setMarca("s/m");
            this->setModelo("s/m");
            this->setAno(0);
        }
        Vehiculo(string marca, string modelo, int ano){
            this->setMarca(marca);
            this->setModelo(modelo);
            this->setAno(ano);
        }
        
        virtual string getMarca(){
            return this->marca;
        }
        virtual string getModelo(){
            return this->modelo;
        }
        virtual int getAno(){
            return this->ano;
        }

        virtual void setMarca (string marca){
            this-> marca = marca;
        }
        virtual void setModelo(string modelo){
            this->modelo = modelo;
        }
        virtual void setAno (int ano){
            this->ano = ano;
        }

    virtual void encenderVehiculo(){
        cout << "El Vehiculo " << marca << " acaba de encender" << endl;
    }
    virtual void apagarVehiculo(){
        cout << "El Vehiculo " << marca << " acaba de apagarse" << endl;
    }
};
class Automovil: public Vehiculo{
    private:
        int pasarejos;
        string tipo;
    public:
        Automovil(string marca, string modelo, int ano, int pasajeros, string tipo) : Vehiculo(marca, modelo, ano){
            this->setPasajeros(pasajeros);
            this->setTipo(tipo);
        } 

        int getPasajero(){
            return this->pasarejos;
        }
        string getTipo(){
            return this->tipo;
        }

        void setPasajeros(int pasajeros){
            this->pasarejos = pasajeros;
        }
        void setTipo(string tipo){
            this->tipo = tipo;
        }

        void encenderVehiculo() override{
            cout << "El Automovil " << marca << " acaba de encender" << endl;
        }
        void apagarVehiculo() override{
            cout << "El Automovil " << marca << " acaba de apagarse" << endl;
        }
};
class Motocicleta : public Vehiculo {
    private: 
        int velocidades;
        string clase;
    public:
        Motocicleta(string marca, string modelo, int ano, int velocidades, string clase) : Vehiculo(marca, modelo, ano) {
            this->setVelocidades(velocidades);
            this->setClase(clase);
        }

        int getVelocidades(){
            return velocidades;
        }
        string getClase(){
            return clase;
        }

        void setVelocidades(int velocidades){
            this->velocidades = velocidades;
        }
        void setClase(string clase){
            this->clase = clase;
        }
        
        void encenderVehiculo() override{
            cout << "La Motocicleta " << marca << " acaba de encender" << endl;
        }
        void apagarVehiculo() override{
            cout << "La Motocicleta " << marca << " acaba de apagarse" << endl;
        }


};



int main (){

Vehiculo* Vh1 = new Automovil("Mclares","720S",2022,4,"Deportivo");
Vehiculo* Vh2 = new Motocicleta("Yamaha","345-TY",2023,5,"Carrera");


cout <<"-Encender Vehiculos-" << '\n';

Vh1->encenderVehiculo();
Vh2->encenderVehiculo();

cout << '\n';

cout <<"-Apagar Vehiculos-" << '\n';

Vh1->apagarVehiculo();
Vh2->apagarVehiculo();

cout << '\n';

    return 0;
}