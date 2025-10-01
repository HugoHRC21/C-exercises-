#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class figure{
    public:
        virtual float calculateArea() = 0;

        virtual void showInfo(){
            cout << "Soy una figura. ";
        }

        virtual float operator+(figure*) = 0;
};

class circle : public figure{
    private:
        float radio;
    public:
        circle(float r) : radio(r) {}

        float calculateArea() override {
            return M_PI * radio*radio;
        }

        void showInfo() override {
            figure::showInfo();
            cout << "Circle area is: " << calculateArea() << endl; 
        }

        float operator+(figure* rectangle){
            return this->calculateArea() + rectangle->calculateArea();
        }
};

class rectangle : public figure{
    private:
        float base;
        float height;
    public:
        rectangle(float b, float h) : base(b), height(h) {}

        float calculateArea() override {
            return base * height; 
        }

        void showInfo() override {
            figure::showInfo();
            cout << "Rectangle area is: " << calculateArea() << endl;
        }

         float operator+(figure* circle){
            return this->calculateArea() + circle->calculateArea();
        }
};



void printArea(figure* figure){
    figure->showInfo();
}


int main(){
    int n;
    cin >> n;
    figure** figures = new figure*[n];
    figures[0] = new circle(3.4);
    figures[1] = new rectangle(3.3,3.3);

    for(int i=0;i<2;i++){
        printArea(figures[i]);
    }

    cout << "Total Area: " << *figures[0] + (figures[1]) << endl;

    // circle bola(3.4);
    // rectangle nobola(3.3,3.3);

    // printArea(&bola);
    // printArea(&nobola);

    // cout << "Total Area: " << bola + &nobola << endl;

    delete[] figures[0];
    delete[] figures[1];
    delete[] figures;

    return 0;
}