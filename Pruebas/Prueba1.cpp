/*Escriba un programa que solicite una hora en formato HH.MM.SS y calcule la hora que corresponde un segundo despues. EL programa debe considerar 
correctamente los cambios de minuto, hora y el cambio de dia a las 00:00:00 si es necesario*/


#include <iostream>
#include <string>

using namespace std;

void validate_input(int hora, int min, int seg) {
    if (hora < 0 || hora > 23 || min < 0 || min > 59 || seg < 0 || seg > 59)
        throw invalid_argument("Invalid hour, minute or seconds");
}

int main(){
    
    int hora, min, seg;
    do {
        cout<< "ingrese una hora en formato HH.MM.SS: " << endl;
        cout<< "Hora: ";
        cin >> hora; 
        cout<< "Minutos: ";
        cin >> min; 
        cout<< "Segundo: ";
        cin >> seg;

        try
        {
            validate_input(hora, min, seg);
            break;
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
        }
        
    } while(true);


    cout << "Hora ingresada: " << hora << ":" << min << ":" << seg << "\n" << endl;

    seg++;

    if(seg == 60){
        seg = 0;
        min++;
    }
    if(min == 60){
        min = 0;
        hora++;
    }
    if(hora == 24){
        hora = 0;
    }

    cout << "Hora un segundo despues: " << (hora < 10 ? "0" + to_string(hora) : to_string(hora)) << ":" << (min < 10 ? "0" + to_string(min) : to_string(min)) << ":" << (seg < 10 ? "0" + to_string(seg) : to_string(seg)) << endl;
    return 0;
}