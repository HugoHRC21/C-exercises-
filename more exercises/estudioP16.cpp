#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class acount_bank{
    private:
        double balance;

    public:
        acount_bank() : balance(0){}

        void deposit(double amount){
            if(amount > 0){
                balance+= amount;
                cout << "deposited: " << amount << endl;
            } else {
                cout << " invalid amount " <<endl;
            }
        }
    
        void show_balance(){
            cout << "Balance: " << balance << endl;
        }
};

int main(){
    acount_bank provincial;

    provincial.show_balance();
    provincial.deposit(356.70);
    provincial.show_balance();

    provincial.deposit(4.3);
    provincial.show_balance();

 

    return 0;
}