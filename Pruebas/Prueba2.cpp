/*escribe un programa que solicite al usuario dos fechas en un mismo ano, 
formato DD/MM y calcule el numero exacto de dias que hay entre ambas fechas. Suponga que el ano no es bisiesto */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define JANUARY 1
#define DO_NOT_SUM 0

int main(){
        int D1, M1, D2, M2, calendar[12] = {1, -1, 0, 0, 1, 1, 2, 3, 3, 4, 4, 5};
        cout << "Ingrese la Primera fecha (DD/MM): " << endl; cin >> D1 >> M1;
        cout << "Ingrese la Segunda fecha (DD/MM): " << endl; cin >> D2 >> M2;
        auto early_date = (D1 + (M1 == JANUARY ? DO_NOT_SUM : (30*(M1-1)+calendar[M1-2])));
        auto late_date = (D2 + ( M2 == JANUARY ? DO_NOT_SUM : (30*(M2-1)+calendar[M2-2])));
        cout << "Dias entre las fechas: "
             << abs(late_date - early_date)   
             << endl;
        return 0;
}