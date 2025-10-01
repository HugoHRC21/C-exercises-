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

void new_person(){
   fstream np ("")
}


int main() {
try{
   fstream HUGO ("NuevoArchivo.txt", ios::in | ios::out | ios::app);
   validate_open_file(&HUGO);

} catch(const exception& e){
      cerr << e.what() << '\n';
      return 1;
}


  
   return 0;
}



