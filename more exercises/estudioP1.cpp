/*Escriba un programa que pida al usuario que introduzca dos enteros, 
que obtenga los números por parte del usuario, después que imprima las palabras “es más grande”. 
Si los números son iguales, que imprima el mensaje
“Estos números son iguales”. Solamente utilice la forma de selección simple de la instrucción if, que
aprendió en este capítulo*/

#include <iostream>

using namespace std;

int main(){
    int x,y;

    cout << "Introduzca un numero entero" << endl;
    cin >> x;
    cout << "Introduzca un segundo numero entero" << endl;
    cin >> y;

    if (x > y){
        cout << "El primer numero ingresado es mas grande" <<endl;
    } else if (y > x){
        cout << "el segundo numero ingresado es mas grande"<< endl;
    } else {
        cout << "Estos numeros son iguales" << endl;
    }
    
    return 0;

}