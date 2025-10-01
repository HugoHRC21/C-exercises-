#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class calculator{
    public:
        int sumar(int a, int b){
            return a + b;
        }
        float sumar(float a, float b){
            return a + b;
        }
};


int main(){
    calculator casio;

    cout << "Suma de enteros: "<< casio.sumar(234,6) << endl;
    cout << "Suma de Flotantes: "<< casio.sumar(5.5f,10.5f) << endl;
   

    return 0;
}