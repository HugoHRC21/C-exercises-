#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    ofstream coyote ("coyote.txt");
    for(char letra = 'A'; letra <= 'Z'; letra++){
        coyote<<letra;
    }
    coyote.close();
    cout << "Lista la vaina" << endl;
    
    return 0;
} 