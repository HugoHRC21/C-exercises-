/*Ejercicio 2: Arreglo Dinámica de Números 
Escribe una clase ArregloNumeros que:
    Almacene un arreglo dinámico de enteros. 
    Permita agregar un número al final. 
    Permita eliminar el último número. 
    Muestre todos los números almacenados. 
En el Main, crea un ArregloNumeros, agrega 5 números, muestra los datos, elimina dos y vuelve a mostrar el estado final del arreglo.*/

# include <iostream>

using namespace std;

class NumArrays {
    private:
        int *items;
        int size;
        int original_size;
    public:

        NumArrays() {
            this -> original_size = 10000;
            this -> items = new int[10000];
            this -> size = 0;
        }

        NumArrays(int n) {
            this -> original_size = n;
            this -> size = 0;
            this -> items = new int[n];
        }

        ~NumArrays() {
            delete[] this -> items;
            this -> size = 0;
        }

        void push_back(int item) {
            this -> items[this->size] = item;
            this->size++;

            if (this -> size >= original_size) throw invalid_argument("Error");
        }

        bool pop_back() {
            if (this->size == 0) return false;

            this->size--;
            return true;
        }


        void show_info() {
            for (int i{0}; i < this -> size; i++)
                cout << this -> items[i] << " ";

            cout << "\n";
        }

};

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    NumArrays array(n);

    array.push_back(67);
    array.push_back(-67);
    array.push_back(0);
    array.push_back(4);
    array.push_back(-4);

    array.show_info();

    array.pop_back();
    array.pop_back();

    
    array.show_info();

    return 0;
}


// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>
// #include <vector>

// using namespace std;

// class numberArrangements {
//     private:
//         vector<int> container;
//     public:
//         void addNumbers(int number){
//             container.push_back(number);
//         }
//         void deleteNumbers(){
//             container.pop_back();
//             cout << "A number has been deleted" << endl;
//             }
//         void showNumbers(){
//             cout << endl;
//             cout << "Stored numbers: " << endl;
//             for(int i = 0; i < container.size(); i++){
//                 cout << i+1 << ".Numbers: " << container[i] << endl;
//             } cout << endl;
//         }
// };

// int main(){
//     numberArrangements box;

//     box.addNumbers(4);
//     box.addNumbers(56);
//     box.addNumbers(789);
//     box.addNumbers(23);
//     box.addNumbers(41);   

//     box.showNumbers();

//     box.deleteNumbers();
//     box.deleteNumbers();

//     box.showNumbers();


//     return 0;

// }