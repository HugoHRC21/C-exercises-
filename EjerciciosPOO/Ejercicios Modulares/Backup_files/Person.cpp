#include <Person.h>

using namespace std;

// Estructura para almacenar la información de una persona
struct Person {
    string name;
    int age;
    string career;
    string id;

    string to_string() const {
        return name + "," + std::to_string(age) + "," + career + "," + id;
    }
};
