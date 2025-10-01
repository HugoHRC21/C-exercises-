/*Ejercicio palindromo*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void validate_imput(int x){
    if(x < 0)
        throw invalid_argument("El valor debe ser estrictamente positivo \n");
}

int main(){
    int x,original, invertido = 0, digito;
    do{
        cout<<"Ingrese un numero entero positivo: "; cin >> x;
            try{ validate_imput(x); break; }
            catch(const exception& e){cerr << e.what() << '\n';}
    } while (true);

    original = x;

    while(x>0){
        digito = x%10;
        invertido = invertido * 10 + digito;
        x/=10;
    }

    if(original==invertido){
        cout << "El numero "<< original << " es un Palindromo :)" <<endl;
    } else {
        cout << "El numero "<< original << " NO es un Palindromo :(" <<endl;
    }
    return 0;
}