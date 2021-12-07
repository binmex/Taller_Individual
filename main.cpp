#include <iostream>
#include <string>
#include "Management.h"


using namespace std;
Management *tor;

void addEmployee();

void findEmployee();

void showLast();

void showFirst();

void showList();

void listEmployee();

void deleteEmployee();

void addEmployeeSorted();

void addEmployeeAfterTo();

void addEmployeeBeginTo();

void addEmployeeFinal();

void showListCant();

int main() {
    tor = new Management();
    char op;
    string menu = "=====Menu=====\n\nDigite una opcion";
    string opciones = "1. [agregar empleado al principio]\n"
                      "2. [agregar empleado al final]\n"
                      "3. [agregar empleado antes de ]\n"
                      "4. [agregar empleado despues de]\n"
                      "5. [agregar empleado ordenado]\n"
                      "6. [Buscar empleado]\n"
                      "7. [Eliminar Empleado]\n"
                      "8. [Obtener lista de empleados]\n"
                      "9. [Mostrar cantidad de empleados]\n"
                      "r. [mostrar primer empleado]\n"
                      "l. [Mostrar ultimo empleado]\n"
                      "X. [Salir]";
    do {
        //string op;
        cout << menu << endl;
        cout << opciones << endl;
        cout << "escriba su seleccion: ";
        op = getchar();
        switch (op) {
            case '1':
                addEmployee();
                break;
            case '2':
                addEmployeeFinal();
                break;
            case '3':
                addEmployeeBeginTo();
                break;
            case '4':
                addEmployeeAfterTo();
                break;
            case '5':
                addEmployeeSorted();
                break;
            case '6':
                findEmployee();
                break;
            case '7':
                deleteEmployee();
                break;
            case '8':
                listEmployee();
                break;
            case '9':
                showListCant();
                break;
            case 'r':
                showFirst();
                break;
            case 'l':
                showLast();
                break;
        }

    } while (toupper(op) != 'X');
    cout << "Gracias" << endl;
    delete(tor);
    return EXIT_SUCCESS;
}

void addEmployee() {
    string name, lastName, charge, id;
    short age;
    char names[30];

    try {
        cout << "\n\n=====agregar empleado=====" << endl;
        cout << "Escriba el nombre del empleado: ";
        cin >> name;
        //gets(names);
        cout << "escriba el apellido del empleado: ";
        cin >> lastName;
        cout << "Escriba la edad del empleado: ";
        cin >> age;
        cout << "Escriba el cargo del empleado";
        cin >> charge;
        cout << "escriba el ID del empleado: ";
        cin >> id;
        cout << "==================" << endl;
        if (tor->addEmpleoyee(name, lastName, charge, id, age) == true){
            cout <<"¡Empleado agrgado correctamente!";
        } else{
            cout <<"¡No se pudo agregar el empleado :(!";
        }

    } catch (exception x) {
        cout << "Error: " << x.what();
    }

}

void addEmployeeFinal() {
    string name, lastName, charge, id;
    short age;
    char names[30];

    try {
        cout << "\n\n=====agregar empleado=====" << endl;
        cout << "Escriba el nombre del empleado: ";
        cin >> name;
        //gets(names);
        cout << "escriba el apellido del empleado: ";
        cin >> lastName;
        cout << "Escriba la edad del empleado: ";
        cin >> age;
        cout << "Escriba el cargo del empleado";
        cin >> charge;
        cout << "escriba el ID del empleado: ";
        cin >> id;
        cout << "==================" << endl;
        if (tor->addEmpleoyeeFinal(name, lastName, charge, id, age)){
            cout <<"¡Empleado agrgado correctamente!";
        } else{
            cout <<"¡No se pudo agregar el empleado :(!";
        }
    } catch (exception x) {
        cout << "Error: " << x.what();
    }
}

void addEmployeeBeginTo() {
    string name, lastName, charge, id, idBeginTo;
    short age;
    char names[30];

    try {
        cout << "\n\n=====agregar empleado=====" << endl;
        cout << "Escriba el nombre del empleado: ";
        cin >> name;
        //gets(names);
        cout << "escriba el apellido del empleado: ";
        cin >> lastName;
        cout << "Escriba la edad del empleado: ";
        cin >> age;
        cout << "Escriba el cargo del empleado";
        cin >> charge;
        cout << "escriba el ID del empleado: ";
        cin >> id;
        cout << "==================" << endl;
        cout << "Ingrese el id del empleado anterior" << endl;
        cin >> idBeginTo;
        cout << "=============" << endl;
        cout << tor->addEmployeBeginTo(name, lastName, charge, id, age, idBeginTo);
    } catch (exception x) {
        cout << "Error: " << x.what();
    }
}

void addEmployeeAfterTo() {
    string name, lastName, charge, id, idAfterTo;
    short age;
    char names[30];

    try {
        cout << "\n\n=====agregar empleado=====" << endl;
        cout << "Escriba el nombre del empleado: ";
        cin >> name;
        //gets(names);
        cout << "escriba el apellido del empleado: ";
        cin >> lastName;
        cout << "Escriba la edad del empleado: ";
        cin >> age;
        cout << "Escriba el cargo del empleado";
        cin >> charge;
        cout << "escriba el ID del empleado: ";
        cin >> id;
        cout << "==================" << endl;
        cout << "Ingrese el id del empleado siguiente" << endl;
        cin >> idAfterTo;
        cout << "=============" << endl;
        if (tor->addEmployeAfterTo(name, lastName, charge, id, age, idAfterTo) == true){
            cout << "Agregado correctamente";
        } else{
            cout<<"fallo";
        }

    } catch (exception x) {
        cout << "Error: " << x.what();
    }
}

void addEmployeeSorted() {
    string name, lastName, charge, id;
    short age;
    char names[30];

    try {
        cout << "\n\n=====agregar empleado=====" << endl;
        cout << "Escriba el nombre del empleado: ";
        cin >> name;
        //gets(names);
        cout << "escriba el apellido del empleado: ";
        cin >> lastName;
        cout << "Escriba la edad del empleado: ";
        cin >> age;
        cout << "Escriba el cargo del empleado";
        cin >> charge;
        cout << "escriba el ID del empleado: ";
        cin >> id;
        cout << "==================" << endl;
        cout << tor->addEmpleoyeeFinal(name, lastName, charge, id, age);
    } catch (exception x) {
        cout << "Error: " << x.what();
    }
}

void deleteEmployee() {
    string id;
    cout<<"=====Eliminar Empleado=====";
    cout<<"ingrese el id del empleado que desea eliminar: ";
    cin>>id;
    //tor->deleteEmployee(id);
}

void listEmployee() {
    cout << "==============Lista de empleados==============";
    tor->listEmployee();
}

void showListCant() {
    cout<<"=====Cantidad de empleados====="<<endl;
    cout<<tor->contEmployee();
}

void showFirst() {
    tor->getFirst();

}

void showLast() {
    tor->getLast();
}


void findEmployee() {
    string id;
    cout << "=====buscar empleado=====" << endl;
    cout<<"ingrese el Id del Empleado: ";
    cin>> id;
    tor->findEmployee(id);
}


