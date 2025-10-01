#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>


using namespace std;


void validate_open_file(const fstream* n){
   if(!n){
      throw runtime_error("Error: no se pudo abrir");
   }
}

   int main() {
      try {
         fstream outFile("archivo_no_existene.txt", ios::in | ios::out | ios::app);
  
         validate_open_file(&outFile);
   
         outFile << "ale mi amor3123234\n";

         outFile.close();
  
         cout << "Contenido escrito con éxito." << std::endl;
      } catch (const exception& e) {
          cerr << e.what() << endl;
          return 1;  
      }
  
      return 0;
  }



