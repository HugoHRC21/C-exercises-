#include <iostream>
#include <string>

using namespace std;

unsigned int simpleHash(string key) {
    unsigned int hash = 0;
    for (char c : key) {
        hash += c; 
    }
    return hash % 100; 
}

int main() 
{
    string key = "HugoRivaws";
    cout << "Hash de " << key << ": " << simpleHash(key) << endl;

    key = "Bob";
    cout << "Hash de " << key << ": " << simpleHash(key) << endl;

    return 0;
}