#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <HashTable.h>
#include <string>
using namespace std;

// Funciones para manejar el archivo
void load_data(HashTable& table, const string& filename);
void save_data(const HashTable& table, const string& filename);

// Funciones CRUD
void create_person(HashTable& table);
void read_person(HashTable& table);
void update_person(HashTable& table);
void delete_person(HashTable& table);
void get_all_people(const HashTable& table);
void show_menu();


#endif