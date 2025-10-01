/*Escribe un programa que solicite al usuario un numero entero 
positivo y lo convierta en su representacion binaria. 
No se permite el uso de funicones ni bibliotecas que conviertan 
directamente al sistema binario*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void validate_input(int val) {
    if ( val < 0)
        throw invalid_argument("Value must be strictly positive");
}

int main(){
    int x,y;
    vector<int> caja;

    do
    {
        cout << "Ingrese un numero Entero Positivo" << endl;
        cin >> x;

        try
        {
            validate_input(x);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    } while (true);
    
    cout << "El numero " << x << " en Binario es: \n";
    
    while(x > 0){
        y = x%2;
        caja.push_back(y);
        x = x/2;
    }

    for (int i{caja.size() - 1}; i >= 0; i--)
        cout << caja[i] << "";
    cout << "\n";

    return 0;
}