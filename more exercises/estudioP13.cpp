#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class book{
    public:
        string qualification;
        string author;

        book(string a , string b){
            qualification = a;
            author = b;
            cout << "libro creado: " << qualification << " su autor es: " << author << endl;
        }

        ~book(){
            cout << "se destruyo el libro: "<< qualification <<" ,para liberar espacio" << endl;
        }
};



int main(){

    book book1("Terapy","Hugo Rivas");


    return 0;
}