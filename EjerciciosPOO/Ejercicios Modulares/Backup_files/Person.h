#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    string career;
    string id;

    string to_string() const;
};

#endif