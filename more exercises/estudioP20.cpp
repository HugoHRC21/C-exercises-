#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class person{
    private:
        string name;
        int age;
    public:
        person(string n, int a) : name(n) {
            this->setAge(a);
        }
        string get_Name(){
            return this-> name;    
        }
        int get_Age(){
            return this -> age;
        }
        void setAge(int a){
            if(a < 0) throw invalid_argument("Age must be non-negative");
            this -> age = a;
        }
        virtual void showInfo(){
            cout << "Name: " << this-> name << ", Age: " << this-> age;
        }
};

class student : public person {
    private:
        float average;
    public:
        student(string n, int a, float p) : person(n,a){
            this -> setAverage(p);
        }
        float get_Average(){
            return this->average;
        }
        void setAverage(float p){
            if(p < 0 or p > 20.00) throw invalid_argument("Average cannot be less than 0.0");
            this -> average = p;
        }

        void showInfo(){
            person::showInfo();
            cout << ", Average: " << this -> average << endl;

        }
};
int main(){
    // student* hugo = new student("Hugo", 23, 19.89);
    // hugo->showInfo();
    // delete hugo;


    int n;
    cout << "Ingrese el numero de elemnetos: ";
    cin >> n; cout << "\n";  

    student** box = new student*[n];


    for(int i = 0; i < n; i++){
        string name;    
        int age;
        float avarage;

        cout << "enter the name of student number " << i+1 << ": ";
        cin >> name;
        cout << "enter the age of student number " << i+1 << ": ";
        cin >> age;
        cout << "enter the avarage of studet number " << i+1 << ": ";
        cin >> avarage;
        cout << "\n"; 
        box[i]= new student(name,age,avarage);


        box[i]->showInfo();
        cout << "\n"; 

    }

    delete[] box;

    return 0;
} 