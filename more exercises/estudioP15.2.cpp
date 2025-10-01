#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "Sonido de animal" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "¡Miau!" << endl;
    }
};

int main() {
    Animal* miAnimal = new Gato();
    miAnimal->hacerSonido(); 
    delete miAnimal; 
    return 0;
}