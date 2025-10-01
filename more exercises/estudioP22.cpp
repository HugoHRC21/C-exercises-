#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;



int main(){
   ofstream EB ("pruebaDeAbrirYLectura.txt", ios::out | ios::trunc);

   EB << "Borrar todo lo anterior y escribri esto" << endl;
   EB.close();
   
   ifstream EL ("registros.txt", ios::in | ios::binary);
   string lectura;

   if(!EL.is_open()){
      cerr << "El archivo no abrio" << endl;
      return 1;
   } else {
      while(getline(EL,lectura)){
         cout << lectura << endl;
      }
      EL.close();
   }

return 0;

}

