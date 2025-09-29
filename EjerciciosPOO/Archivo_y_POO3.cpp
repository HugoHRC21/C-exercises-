#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <regex>
#include <iomanip>
#include <locale>
#include <codecvt>


using namespace std;

class DataBaseEntry{
    private: 
        wstring nombre;
        int edad;
        wstring correo;

    public:
        wstring getNombre() const {
            return this->nombre;
        }
        int getEdad() const{
            return this->edad;
        }
        wstring getCorreo() const{
            return this->correo;
        }
        
        void setNombre(wstring nombre){
            this->nombre = nombre;
        }
        void setEdad(int edad){
            this->edad = edad;
        }
        void setCorreo (wstring correo){
            wregex expreRegu(L"^[\\w\\.-]+@[\\w\\.-]+\\.[\\w]+$");

            if(regex_match(correo, expreRegu)){
                this->correo = correo;
            }
        }

        void imprimir(){
            wcout << getNombre() << L":" << getEdad() << L":" << getCorreo() << endl;
        }
};



vector<DataBaseEntry> loadDatabase (const string& filename){
    vector<DataBaseEntry> database;
    wifstream file (filename);
    file.imbue(locale(file.getloc(), new codecvt_utf8<wchar_t>));
    
    if (file.bad()) throw runtime_error("File not found or corrupted");
    
    while( file.good() ) {
        wstring edad, nombre, correo;
        DataBaseEntry entry;


        getline(file, nombre, L':');

        if (file.eof()) break;

        entry.setNombre(nombre);

        getline(file, edad, L':');
        entry.setEdad(stoi(edad));

        getline(file, correo);
        entry.setCorreo(correo);

        database.push_back(entry);
    }
    
    file.close();
    return database;
}

 void saveDatabase(const string& filename, const vector<DataBaseEntry>& database){
     wofstream file (filename);
     file.imbue(locale(file.getloc(), new codecvt_utf8<wchar_t>)); 
     if (file.is_open()){
         for ( auto entry : database){
             file << entry.getNombre() << L":" << entry.getEdad() << L":" << entry.getCorreo() << endl;
         }
         file.close();
     }
 }

 
int main(){

// setlocale(LC_ALL, "en_US.utf8");// Configuración de la localización para imprimir caracteres anchos
// locale loc("en_US.UTF-8");
// wcout.imbue(loc); 


vector<DataBaseEntry> database = loadDatabase("OtrapincheDatabase.txt");

while(true){
    char choice;
    cout << L"Menú:" << '\n';
    cout << L"1. Agregar nueva entrada" << endl;
    cout << L"2. Editar entrada existente" << endl;
    cout << L"3. Eliminar entrada" << endl;
    cout << L"4. Mostrar todas las entradas" << endl;
    cout << L"5. Guardar y salir" << endl;
    cout << L"Elija una opción: " << '\n';
    cin >> choice;
    cout << L"OPCION ELEGIDA: " << choice << "\n";

    switch (choice){
    case '1': {
        DataBaseEntry newEntry = DataBaseEntry();

        wstring nombre, correo, edad;

        cout << L"Ingrese el nombre: ";
        cin.ignore();
        getline(wcin, nombre);
        newEntry.setNombre(nombre);

        cout << L"Ingrese la Edad: ";
        getline(wcin,edad);
        newEntry.setEdad(stoi(edad));

        cout << L"Ingrese el correo electronico: ";
        getline(wcin,correo);
        newEntry.setCorreo(correo);

        database.push_back(newEntry);
        saveDatabase("OtrapincheDatabase.txt", database);

        break;            
    }
    case '2': {
        int indice;
        wstring nombre, correo, edad;
 
        cout << L"Ingrese el indice de la entrada editar: ";
        cin >> indice;
        if(indice >= 0 and indice < database.size()){
            wcout << L"introduzca nuevo nombre: ";
            cin.ignore();
            getline(wcin, nombre);
            database[indice].setNombre(nombre);

            cout << L"Introduzca nueva edad: ";
            cin.ignore();
            getline(wcin,edad);
            database[indice].setEdad(stoi(edad));
            
            cout << L"Introduzca nuevo correo electronico: ";
            cin.ignore();
            getline(wcin,correo);
            database[indice].setCorreo(correo);

            saveDatabase("OtrapincheDatabase.txt", database);
            
            cout << L"Edicion exitosa "<< endl;
        } else {
            cout << L"Indice invalido" << endl;
        }
        break;
    }
    case '3': {
        int indice;
        wstring nombre, edad, correo;

        wcout << L"Ingrese el indice de la entrada a eliminar: ";
        cin >> indice;

        if (indice >= 0 and indice < database.size()){
            database.erase(database.begin() + indice);
            saveDatabase("OtrapincheDatabase.txt", database);
            cout << L"Entrada eliminada exitosamente" << endl;
        } else {
            wcout << L"Indice invalido" << endl;
        }
        break;
    }
    case '4': {
            wcout << left << setw(12) << L"Nombre" 
                 << left << setw(6) << L"Edad" 
                 << left << setw(30) << L"Correo Electrónico" << endl;
            wcout << wstring(50, L'-') << endl;

            for (auto i = 0; i < database.size(); i++) {
                wcout << left << setw(12) << database[i].getNombre() << L" |"
                     << setw(6) << database[i].getEdad() 
                     << setw(30) << database[i].getCorreo() << endl;
            }
            break;
        }
    case '5': {
        wcout << L"Adios perrillo!" << endl;
        return 0;
    default: 
        wcout << L"Eleccion invalida, porfavor vuelva a intentarlo" << endl;
        break;
    }
    }
}
    return 0;

}