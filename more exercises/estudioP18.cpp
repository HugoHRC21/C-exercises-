#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
    private:
        string name;
        int age;
        float average;
    public:
        Student(string n, int a, float av) : name(n), age(a), average(av) {}

        virtual void show_info(){
            cout << "Name: " << name << ", Age: " << age <<", Average: " << average << endl;
        }
};

class Postgraduate_studente : public Student{
    private:
        string thesis;
    public:
    Postgraduate_studente(string n, int a, float av, string t): Student(n,a,av), thesis(t) {}
    
    void show_info() override{
        Student::show_info();
        cout << "Thesis: " << thesis << endl;
        }
};

void print_info(Student* student){
    student->show_info();
};

int main(){
    Student BotiElCatire("Botis", 12, 16.7);
    Postgraduate_studente OlfaElLider("Olaf", 12, 18.7, "Filosofia");

    print_info(&BotiElCatire);
    print_info(&OlfaElLider);



    return 0;
}