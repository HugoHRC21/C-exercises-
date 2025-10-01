#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// class ClassB;
class ClassA{
    private:
        int number = 42;
    public:
        friend class ClassB;
};

class ClassB{
    public:
        void showNumber(ClassA& a){
            cout << "Number: " << a.number << endl;
        }
};



int main(){
    ClassA At1;
    ClassB At2;
    At2.showNumber(At1);

    return 0;
}