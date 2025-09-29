#include <iostream>
#include <fstream>
#include <sstream>
#include <HashTable.h>

using namespace std;

void load_data(HashTable& table, const string& namefile) {
    ifstream file(namefile);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Person person;
        getline(ss, person.name, ',');
        ss >> person.age;
        ss.ignore(1); // Ignorar la coma
        getline(ss, person.career, ',');
        getline(ss, person.id, ',');
        table.insert(person);
    }
}

void guardarDatos(const HashTable& table, const string& namefile) {
    ofstream file(namefile);
    for (const auto& person : table.get_all()) {
        file << person.to_string() << endl;
    }
}

// Funciones CRUD
void create_person(HashTable& table) {
    Person new_person;
    cout << "Enter name: ";
    cin >> new_person.name;
    cout << "Enter age: ";
    cin >> new_person.age;
    cout << "Enter career: "; 
    cin >> new_person.career;
    cout << "Enter ID: ";
    cin >> new_person.id;
    table.insert(new_person);
    cout << "Person added successfully." << endl;
}

void rear_person(HashTable& table) {
    string id;
    cout << "Enter the ID of the person to search: ";
    cin >> id;
    Person person;
    if (table.search(id, person)) {
        cout << "Name: " << person.name << ", Age: " << person.age << ", Career: " << person.career << endl;
    } else {
        cout << "Person not found." << endl;
    }
}

void update_person(HashTable& table) {
    string id;
    cout << "Enter the ID of the person to update: ";
    cin >> id;
    Person person;
    if (table.search(id, person)) {
        cout << "Enter the new name: ";
        cin >> person.name;
        cout << "Enter the new age: ";
        cin >> person.age;
        cout << "Enter the new career: ";
        cin >> person.career;
        table.remove(id); // Eliminar la entrada antigua
        table.insert(person); // Insertar la nueva entrada
        cout << "Person updated successfully." << endl;
    } else {
        cout << "Person not found.." << endl;
    }
}

void delete_person(HashTable& table) {
    string id;
    cout << "Enter the ID of the person to delete: ";
    cin >> id;
    table.remove(id);
    cout << "Person successfully deleted." << endl;
}

void get_all_people(const HashTable& table) {
    vector<Person> people = table.get_all();
    if (people.empty()) {
        cout << "Empty data." << endl;
    } else {
        cout << "List of people:" << endl;
        for (const auto& person : people) {
            cout << "Name: " << person.name << ", Age: " << person.age << ", Career: " << person.career << ", ID: " << person.id << endl;
        }
    }
}

void show_Menu() {
    cout << "Menu Options:" << '\n';
    cout << "1. Create Person" << '\n';
    cout << "2. Read Person" << '\n';
    cout << "3. Update Person" << '\n';
    cout << "4. Delete Person" << '\n';
    cout << "5. View All Persons" << '\n'; 
    cout << "6. Exit" << '\n';
}
