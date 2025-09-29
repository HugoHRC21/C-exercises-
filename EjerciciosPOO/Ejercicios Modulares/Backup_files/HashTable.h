#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <list>
#include <Person.h>

using namespace std;

class HashTable {
private:
    vector<list<Person>> table;
    int size;

    int hash_function(const string& id);
    
public:
    HashTable(int tam);
    void insert(const Person& person);
    bool search(const string& id, Person& person);
    void remove(const string& id);
    vector<Person> get_all() const;
};

#endif