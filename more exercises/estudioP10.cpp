/*Crea un programa que modele un sistema de gestión de libros utilizando estructuras y 
estructuras anidadas. El sistema debe permitir almacenar información sobre libros y sus autores.

    Estructura Autor:
nombre (string)
apellido (string)
nacionalidad (string)
    Estructura Libro:
titulo (string)
anioPublicacion (int)
autor (estructura Autor, anidada)

Permitir al usuario ingresar información sobre varios libros.
Mostrar la lista de libros con sus detalles, incluyendo información del autor.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct author{
    string first_name;
    string last_name;
    string nacionality;
};
struct book{
    string qualification;
    string Year_Publication;
    author author_l;
};

int main(){

    int x = 1;
    book books [x];

    for (int i = 0; i < x; i++){
        cout <<"Ingrese el titulo del libro: " << endl;
        getline(cin, books[i].qualification);
        cout <<"Ingrese el Ano de publicacion del libro: " <<endl;
        getline(cin, books[i].Year_Publication);
        cout <<"Ingrese el Nombre, Apellido y nacionalidad del autor: "<<endl;
        cout << "First Name: "; getline(cin,books[i].author_l.first_name);
        cout << "Last Name: "; getline(cin,books[i].author_l.last_name);
        cout << "Natioanlity: "; getline(cin,books[i].author_l.nacionality);
        cout << endl;
    }

    for (int i = 0; i < x; i++)    {
        cout << "Informacion del libro #" << i << ": " <<endl;
        cout << "   Qualification: " << books[i].qualification <<endl;
        cout << "   Year of Publication: " << books[i].Year_Publication <<endl;
        cout << "   Author-> " <<endl;
        cout << "       First Name: " << books[i].author_l.first_name <<endl;
        cout << "       Last Name: " << books[i].author_l.last_name <<endl;
        cout << "       Nacionality: " << books[i].author_l.nacionality <<endl;
        cout << endl;
    }
    return 0;
}