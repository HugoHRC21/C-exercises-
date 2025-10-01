#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class perro{
private:
    public:
        string name;
        int age;

        void bark(){
            cout << name << " tiene " << age << " de edad y dice: guau!" << endl;
        }
};




int main(){

    perro juancho;
    juancho.name = "Juancho";
    juancho.age = 23;

    juancho.bark();

    return 0;
}