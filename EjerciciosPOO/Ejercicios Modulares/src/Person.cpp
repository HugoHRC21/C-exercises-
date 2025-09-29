#include <Person.h>

    string Person::to_string() const {
        return name + "," + std::to_string(age) + "," + career + "," + id;
    }

