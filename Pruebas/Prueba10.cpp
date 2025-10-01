/*Escribe una clase Libro con: 
Título (cadena). 
Autor (cadena). 
Año de publicación (int). 
Luego, crea una clase Biblioteca que: 
Use un arreglo dinámico de objetos Libro. 
Permita agregar un nuevo libro. 
Permita mostrar todos los libros. 
En el main, crea una biblioteca, añade al menos 3 libros y muestra la información*/

# include <iostream>
# include <ctime>


using namespace std;

class Book {
    private:
        string title;
        string author;
        int year;
    public:

        Book() {

        }

        Book(string t, string a, int y) : title(t), author(a) {
            this -> set_year(y);
        }

        void show_info() {
            cout << this -> title << " ";
            cout << this -> author << " ";
            cout << this -> year  << "\n\n";
        }

        void set_year(int y) {
            std::time_t t = std::time(nullptr);
            std::tm *const pTInfo = std::localtime(&t);
            int current_year = 1900 + pTInfo->tm_year;

            if (y < 0 or y > current_year)
                throw invalid_argument("ERROR: Year is invalid");

            this -> year = y;
        }
};

class Library {
    private:
        Book *books;
        int size;

    public:

        Library() {
            this -> size = 0;
            this -> books = new Book[10000];
        }

        void add_book(Book b) {
            this -> books[this -> size] = b;
            size++;
        }

        void show_info() {
            for (int i{0}; i < this -> size; i++) {
                this -> books[i].show_info();
            }
        }

};


int main()
{
    Library l;
    Book b1("Los 3 mosqueteros", "Alexandre Dumas", 2026), b2("100 years of solitude", "Garcia Marquez", 1962), b3("The City and the Dogs", "Mario Vargas Llosa", 1963);


    l.add_book(b1);
    l.add_book(b2);
    l.add_book(b3);

    l.show_info();
    return 0;
}


// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// using namespace std;

// class book{
//     public:
//         string qualification;
//         string author;
//         int PubliYear;

//         book (string q, string a, int py) : qualification(q), author(a), PubliYear(py) {}

//         void ShowInfo(){
//             cout << "Book Information: " << endl;
//             cout << "Qualification: " << qualification << ", Author: " << author << ", Year of Publication: " << PubliYear << "\n" <<endl;
//         }
// };

// class library {
//     private:
//         vector<book>books;
//     public:
//         library(){};

//         void addBooks(book book){
//             books.push_back(book);
//         }
//         void showInfo (){
//             for(int i = 0; i < books.size(); i++){
//                 books[i].ShowInfo();
//             }
//         }
// };

// int main(){

//     library mylibrary;
//     cout << "stored books: \n" << endl;

//     mylibrary.addBooks(book("terapia", "Julio Lugo", -2));
//     mylibrary.addBooks(book("terapia 2", "Luis Heranndez", 2028));
//     mylibrary.addBooks(book("terapia el final ", "Ale Alayala", 2023));

//     mylibrary.showInfo(); 
    

   
//     return 0;

// }