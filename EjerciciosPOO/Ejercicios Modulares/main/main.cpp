#include <iostream>
#include <HashTable.h>
#include <Functions.h>
using namespace std;



int main() {
    HashTable table(10); // Tamaño de la table hash
    const string namefile = "people.txt";

    // Cargar datos iniciales del archivo
    load_data(table, namefile);

    int opcion;
    do {
        show_menu();
        cout << "Select an option: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                create_person(table);
                break;
            case 2:
                read_person(table);
                break;
            case 3:
                update_person(table);
                break;
            case 4:
                delete_person(table);
                break;
            case 5:
                get_all_people(table); // Llamar a la nueva función
                break;
            case 6:
                save_data(table, namefile); // Guardar cambios en el archivo
                cout << "leaving..." << endl;
                break;
            default:
                cout << "Invalid option. try again." << endl;
        }
    } while (opcion != 6);

    return 0; // Fin del programa
}