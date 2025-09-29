#include <HashTable.h>

using namespace std;

HashTable::HashTable(int tam) : size(tam) {
    table.resize(size);
}

int HashTable::hash_function(const string& id) {
    int hash = 0;
    for (char c : id) {
        hash += c;
    }
    return hash % size;
}
    
void HashTable::insert(const Person& person) {
    int index = hash_function(person.id);
    table[index].push_back(person);
}

bool HashTable::search(const string& id, Person& person) {
    int index = hash_function(id);
    for (const auto& p : table[index]) {
        if (p.id == id) {
            person = p;
            return true;
        }
    }
    return false;
}

void HashTable::remove(const string& id) {
    int index = hash_function(id);
    table[index].remove_if([&id](const Person& p) {
        return p.id == id;
    });
}

vector<Person> HashTable::get_all() const {
    vector<Person> People;
    for (const auto& list : table) {
        for (const auto& p : list) {
            People.push_back(p);
        }
    }
    return People;
}

