#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class animal{
    public:
        void eat(){
            cout << "the animal is eating" << endl;
        }
};
class dog : public animal{
    public:
        void bark(){
            cout << "guau!" << endl;
        }
};

int main(){
    animal* mianimal = new dog;
    mianimal->eat();
    return 0;
}