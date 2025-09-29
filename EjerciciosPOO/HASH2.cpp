#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class TableHash{
private: 
    vector <list<pair<string,int>>> tabla;
    int tamano;

    int hashFuntion(string clave){
        int hash;
        for( char c : clave){
            hash += c;
        }
        return hash%tamano;
    }
public:
    TableHash(int tam) : tamano(tam){
        tabla.resize(tamano);
    }

    void insertar(string clave, int valor){
        int indice = hashFuntion(clave);
        tabla[indice].emplace_back(clave,valor);
    }

    bool buscar(string clave, int &valor){
        int indice = hashFuntion(clave);
        for (auto par : tabla[indice]){
            if(par.first == clave){
                valor = par.second;
                return true;
            }
        }
        return false;
    }
    void eliminar(string clave){
        int indice = hashFuntion(clave);
        tabla[indice].remove_if([clave](pair<string,int>par){
            return par.first==clave;
        });
    }
};


int main() 
{
    TableHash th(10);

    th.insertar("julio",28);
    th.insertar("Mafer",26);
    th.insertar("darvis",29);
    th.insertar("ale",22);

    int edad;
    if (th.buscar("julio",edad)){
        cout << "edad de Bob: " << edad << endl;
    } else {
        cout << "Bob no encontrado" << endl;
    }

    th.eliminar("ale");

    return 0;
}