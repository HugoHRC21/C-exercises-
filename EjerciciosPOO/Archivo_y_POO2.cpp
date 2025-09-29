#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct dataBaseEntry {
    string nombre;
    int edad;
    string carrera;
};

vector<dataBaseEntry> loaDataBase (const string& filename){
    vector<dataBaseEntry> database;
    ifstream file (filename);
    
    if (file.bad()) throw runtime_error("File not found or corrupted");
    
    while( file.good() ) {
        string edad;
        dataBaseEntry db;

        getline(file, db.nombre, ',');
        getline(file, edad, ',');
        getline(file, db.carrera);
        
        if (file.eof()) break;

        db.edad = stoi(edad);
        database.push_back(db);
    }
    
    file.close();
    return database;
}

void saveDatabase (const string& filename, const vector<dataBaseEntry>& database){
    ofstream file (filename);
    if(file.is_open()){
        for(const auto& entry : database){
            file<<entry.nombre <<","<<entry.edad <<","<<entry.carrera<<endl;
        }
    file.close();
    }else {
        throw ios_base::failure("Error al guardar el archivo");
    }
}

 
int main(){
    vector<dataBaseEntry> database = loaDataBase("dataPincheBase.txt");
    while(true){
        cout<< "Menu: " << '\n';
        cout<< "1. Crear Nuevo Registro" <<endl;
        cout<< "2. Editar"<<endl;
        cout<< "3. Borrar"<<endl;
        cout<< "4. Ver la Base de Datos"<<endl;
        cout<< "5. Salir"<<endl;

    int choice;
    cout << "Introduzca la opocion que desee" << endl;
    cin >> choice;
    cin.ignore(); 

    switch (choice){
    case 1: {
        dataBaseEntry newEntry;
        cout << "Introduzca el Nombre: ";
        getline(cin, newEntry.nombre);
        cout << "Introduzca la edad: ";
        cin >> newEntry.edad;
        cin.ignore();
        cout << "Introduzca la carrera: ";
        getline(cin,newEntry.carrera);
        database.push_back(newEntry);
        saveDatabase("dataPincheBase.txt", database);
        cout << "Se creo exitosamente la persona" << endl;
        break;
    }
    case 2: {
        int indice;
        cout << "Introduce el indice de la entrada a editar: ";
        cin >> indice;
        cin.ignore();

        if(indice >= 0 and indice < database.size()){
            cout << "introduzca nuevo nombre: ";
            getline(cin, database[indice].nombre);
            cout << "introduzca nueva edad: ";
            cin >> database[indice].edad;
            cin.ignore();
            cout << "inntroduzca nueva carrera: ";
            getline(cin, database[indice].carrera);
            saveDatabase("dataPincheBase.txt",database);
            cout << "Entrada actualizada exitosamente!" << endl;
        } else {
            cout << "Valor invalido" << endl;
        }
        break;
    }
    case 3: {
        int indice;
        cout << "introduzca el indice de la entrada a elimininar: ";
        cin >> indice;
        cin.ignore();
        if (indice >= 0 and indice < database.size()){
            database.erase(database.begin() + indice);
            saveDatabase("dataPincheBase.txt", database);
            cout << "Entrada eliminada exitosamente" << endl;
        } else {
            cout << "Valor invalido" << endl;
        }
        break;

    }
    case 4: {
        int indice;
        cout << "Database: " << endl;
        for (size_t i = 0; i < database.size(); i++){
            auto entry = database[i];
            cout << i << "." << entry.nombre << "," << entry.edad << "," << entry.carrera << endl;
        } 
        break;
    }
    case 5: {
        cout << "Adios perrillo!" << endl;
        return 0;
    default: 
        cout << "Eleccion invalida, porfavor vuelva a intentarlo" << endl;
        break;
    }
    }
}

    return 0;

}
