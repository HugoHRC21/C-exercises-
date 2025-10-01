/*Ejercicio 4: Sistema de Reserva de Vuelos 
Diseña un sistema básico de reserva de vuelos usando clases y memoria dinámica. 
Requisitos: 
1. Crea una clase Vuelo con: 
* Código de vuelo (cadena). 
* Destino (cadena). 
Número total de asientos (int). 
Número de asientos reservados (int). 
2. Implementa métodos para: 
Reservar un asiento. 
Cancelar una reserva. 
* Mostrar los datos del vuelo (incluyendo asientos disponibles). 
3. En el main, permite al usuario crear vuelos, hacer reservas y cancelaciones*/


#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class flight{
    private:
        string code;
        string destination;
        int number_seats;
        int reserved_seats;
    public:
    flight(string c, string d, int s, int rs) : code(c),destination(d) {
        this->set_number_seats(s);
        this->set_reserved_seats(rs);
    }

    void set_number_seats(int a){
        if (a < 0) throw invalid_argument("Age must be non-negative");
        this -> number_seats = a;
    }
    void set_reserved_seats(int b){
        if (b < 0) throw invalid_argument("Age must be non-negative");
        this -> reserved_seats = b;
    }


    bool reserve_seats (){
        if(reserved_seats < number_seats){
            reserved_seats++;
            cout << "seats are reserved " << endl;
            return true;
        } else {
            cout << "there are no seats available" << endl;
            return false;
        }
    }
    bool cancel_reserve (){
        if(reserved_seats > 0){
            reserved_seats--;
            cout << "The reservation was canceled " << endl;
            return true;
        } else {
            cout << "there are no reservations to cancel" << endl;
            return false;
        }
    }
    void show_info(){
        cout << "flight code: " << code << endl;
        cout << "flight destination: " << destination << endl;
        cout << "total seats: " << number_seats << endl;
        cout << "Reserved seats: " << reserved_seats << endl;
        cout << "seats available: " << (number_seats - reserved_seats) << endl;

    }
};

int main(){
    int opcion;
    flight* vuelos[100];
    int counterflights = 0;

    do {
        cout << "Menu:" << endl;
        cout << "1. Create a flight" << endl;
        cout << "2. Make a reservation" << endl;
        cout << "3. Cancel a reservation" << endl;
        cout << "4. Show flight data" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> opcion;


        switch (opcion) {
            case 1: {
                string codigo, destino;
                int total;
                cout << "Enter the flight code: ";
                cin >> codigo;
                cout << "Enter the destination: ";
                cin >> destino;
                cout << "Enter the total number of seats: ";
                cin >> total;
                vuelos[counterflights++] = new flight(codigo, destino, total,0);
                cout << "Flight created successfully" << endl;
                break;
            }
            case 2: {
                int vueloIndex;
                cout << "Enter the flight index: " << counterflights - 1;
                cin >> vueloIndex;
                if (vueloIndex >= 0 && vueloIndex < counterflights) {
                    vuelos[vueloIndex]->reserve_seats();
                } else {
                    cout << "Invalid flight index" << endl;
                }
                break;
            }
            case 3: {
                int vueloIndex;
                cout << "Enter the flight index: "<< counterflights - 1;
                cin >> vueloIndex;
                if (vueloIndex >= 0 && vueloIndex < counterflights) {
                    vuelos[vueloIndex]->cancel_reserve();
                } else {
                    cout << "Invalid flight index" << endl;
                }
                break;
            }
            case 4: {
                int vueloIndex;
                cout << "Enter the flight index: "<< counterflights - 1;
                cin >> vueloIndex;
                if (vueloIndex >= 0 && vueloIndex < counterflights) {
                    vuelos[vueloIndex]->show_info();
                } else {
                    cout << "Invalid flight index" << endl;
                }
                break;
            }
            case 5:
                cout << "Bye" << endl;
                break;
            default:
                cout << "Invalid option, try again" << endl;
        }
    } while (opcion != 5);

   
    for (int i = 0; i < counterflights; i++) {
        delete vuelos[i];
    }
    
    return 0;

}
