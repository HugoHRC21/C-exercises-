#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int x,z,min;
    float key;

    cout << "Ingrese el numero de elementos a ordenar: "; cin >> x;
    vector<float>box_1(x);

    for(int i=0; i<x; i++){        
        cout << "Numero " << i+1 << ": ";
        cin >> box_1[i];
    }
    cout << "\n" << endl;

    vector<float>box_2 = box_1;
    vector<float>box_3 = box_1;


//metodo de la burbuja
for(int i = 0; i < x; i++){
    for(int j=0; j < x-i-1; j++){
        if(box_1[j] > box_1[j+1]){
            swap(box_1[j], box_1[j+1]);
        }
    }
}

//metodo insercion
for(int i=1; i < x; i++){
    key = box_2[i];
    z = i-1;
    while(z >=0 and box_2[z] > key){
        box_2[z+1] = box_2[z];
        z--;
    }
    box_2[z+1] = key;
}

//metodo seleccion
for(int i = 0; i < x -1; i++){
    min = i;
    for(int j = i+1; j < x; j++){
        if(box_3[j] < box_3[min]){
        min = j;
        }
    }
    swap(box_3[i], box_3[min]);
}



//Confimracion 
if(box_1 == box_2 and box_3 == box_1){
    cout << "Los Metodos funcionaron correctamente :)" << endl;
}
else{cout << "Los metodos nos funcionaron correctamente :( "; }
    
    cout << "\n" << endl;


//Imprimir el orden correcto
cout << "\n Arreglo ordenado (Burbuja):";
for(int i=0; i<x; i++){        
        cout << box_1[i]<< ", ";
    }
cout << "\n Arreglo ordenado (insercion):";    
for(int i=0; i<x; i++){        
        cout << box_2[i]<< ", ";
    }
cout << "\n Arreglo ordenado (seleccion):";
for(int i=0; i<x; i++){        
        cout << box_3[i]<< ", ";

}

    return 0;
}