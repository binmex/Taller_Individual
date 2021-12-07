//
// Created by Binmex on 04/12/2021.
//

#include "Management.h"
#include "LinkedDouble.cpp"
#include "Employee.h"
#include <iostream>

LinkedDouble<Employee> *envio = new LinkedDouble<Employee>();;

/**
 *@brief metodo que añade un empleado al principio de la lista
 * @param name string que serequiere con el nombre del empleado
 * @param lastName string que serequiere con el apellido del empleado
 * @param charge string que se requiere con el cargo del empleado
 * @param id string que requiere con el ID del empleado
 * @param age short que requiere la edad del empleado
 * @return un boolean con la informacion true(si se añade el empleado) y false en el caso contrario
 */
bool Management::addEmpleoyee(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    if (envio->findNode(id) == NULL) {
        std::cout << "entra";
        envio->addNodeFirst(Employee(name, lastName, charge, id, age));
        return true;
    } else {
        std::cout << "no entra";
        return false;
    }

}

bool
Management::addEmpleoyeeFinal(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    if (envio->findNode(id) == NULL) {
        envio->addNodeLast(Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}

bool
Management::addEmployeBeginTo(std::string name, std::string lastName, std::string charge, std::string id, short age,
                              std::string idBeginTo) {
    if (envio->findNode(idBeginTo) != NULL && envio->findNode(id) == NULL) {
        envio->addNodeBeforeTo(envio->findNode(idBeginTo), Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}

bool
Management::addEmployeAfterTo(std::string name, std::string lastName, std::string charge, std::string id, short age,
                              std::string idAfterTo) {
    if (envio->findNode(idAfterTo) != NULL && envio->findNode(id) == NULL) {
        envio->addNodeBeforeTo(envio->findNode(idAfterTo), Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}

bool
Management::addEmployeeSorted(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    if (envio->findNode(id) == NULL) {
        envio->addNodeSorted(Employee(name, lastName, charge, id, age));
        return true;
    }
    return false;
}

std::string Management::findEmployee(std::string id) {
    if (envio->findInfo(id) != NULL) {
        return "Nombre: " + envio->findInfo(id)->getName() + " Apellido: " + envio->findInfo(id)->getLastName()
               + " Cargo: " + envio->findInfo(id)->getCharge() + "ID: " + envio->findInfo(id)->getId()
               + " Edad: " + std::to_string(envio->findInfo(id)->getAge());
    } else {
        return "no existe";
    }

}

bool Management::deleteEmployee(std::string id) {
    if (envio->findNode(id) != NULL) {
        envio->deleteNode(envio->findNode(id));
        return true;
    }
    return false;
}

void Management::listEmployee() {
    if (contEmployee() > 0) {
        for (Employee empleados: envio->getList(true)) {
            std::cout << "\n" << empleados << "\n";
        }
    } else {
        std::cout << "esta vacia";
    }
}

int Management::contEmployee() {
    if (envio->getSize() > 0) {
        return envio->getSize();
    } else {
        return -25;
    }

}

std::string Management::getFirst() {
    return " Nombre: " + envio->getFirst().getName() + " Apellido: " + envio->getFirst().getLastName() + "Cargo: " +
           envio->getFirst().getCharge()
           + " ID: " + envio->getFirst().getId() + " Edad: " + std::to_string(envio->getFirst().getAge());
}

std::string Management::getLast() {
    return " Nombre: " + envio->getLast().getName() + " Apellido: " + envio->getLast().getLastName() + "Cargo: " +
           envio->getLast().getCharge()
           + " ID: " + envio->getLast().getId() + " Edad: " + std::to_string(envio->getLast().getAge());
}













