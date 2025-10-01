/*Ejercicio 1: Gestión de Estudiantes 
Escribe una clase Estudiante que contenga: 
Nombre (cadena de caracteres). 
Edad (entero). 
Nota Final (float). 
La clase debe permitir: 
1. Crear un estudiante mediante un constructor que reciba los datos. 
2. Mostrar la información del estudiante. 
3. Cambiar la nota final. 
4. Usar memoria dinámica para almacenar el nombre. 
En el main, crea un objeto Estudiante, muestra sus datos, modifica la nota y vuelve a mostrar los datos.*/

# include <iostream>

using namespace std;

class Student {
    private:
        char * name;
        int age;
        float grade;
    
    public:

        Student(char * name, int age, float grade) {
            set_name(name);
            set_age(age);
            set_grade(grade);
        }

        void set_name(char *name) {
            this -> name = name;
        }

        void set_age(int &age) {
            if (age < 0)
                throw invalid_argument("Age must be non-negative");

            this -> age = age;
        }

        void set_grade (float &grade ) {
            if (grade < 0.0)
                throw invalid_argument("Grade must be non-negative");

            this -> grade = grade;
        }

        void show_info() {
            cout << "Name: "  << this -> name << "\n";
            cout << "Age: "   << this -> age << "\n";
            cout << "Grade: " << this -> grade << "\n\n";
        }

};

int main() {
    Student* carlos = new Student("Juan Pablo", 6, 18.9);
    float new_value = 19.8;
    carlos->show_info();
    carlos->set_grade(new_value);
    carlos->show_info();


        
    delete carlos;  

    return 0;
}


// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>
// #include <vector>

// using namespace std;

// class student{
//     private:
//         const char* name;
//         int age;
//         float finalNote;
//     public:
//         student(const char* n, int a, float fn) : name(n), age(a), finalNote(fn) {}

//         void showInfo () {
//             cout << "Student information: " << endl;
//             cout << "Name: " << name << ", Age: " << age << ", Final Note: " << finalNote << endl;
//         }
//         void change_final_note(float nfn){
//             finalNote = nfn;
//         }
// };

// int main(){
//       student* carlos = new student("", -6, -18.9);
      
//       carlos->showInfo();
//       carlos->change_final_note(19.8);
//       carlos->showInfo();

//       delete carlos;
   
//     return 0;

// }