#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


int countWords(string filename){
    ifstream file (filename);
    string line;
    int wordCount = 0;

    if (file.is_open()){
        while (getline(file, line)){
            stringstream ss(lines);
            string word;
            while(ss>>word){ 
                wordCount++;
            }
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return -1;
    }

    return wordCount;
}

int main(){
    string inputFile = "input.txt";
    string outputFile = "putput.txt";

    int wordCount = countWord(inputFile);
    if(wordCount >= 0) {
        ofstreamout output (outputFile);
        if (output.is_open()){
            output << "El archivo '" << inmputFile << "' contiene" << wordCount << " palabras." << endl;
            output.close();
            cout << "el archivo de salida creado exitosamente: " << outputFile << endl;         
         } else {
            cerr << "Error al abrir el archivo de salida: " << outputFile << endl;
         }
    }
     return 0;


    return 0;
}