//
// Created by Binmex on 04/12/2021.
//

#include "Management.h"
#include "LinkedDouble.cpp"
#include "Employee.h"
#include <iostream>

LinkedDouble<Employee> *envio;


bool Management::addEmpleoyee(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    envio = new LinkedDouble<Employee>();
    if (envio->findInfo(id) != NULL) {
        return false;
    } else {
        envio->addNodeFirst(Employee(name, lastName, charge, id, age));
        return true;
    }

}

bool
Management::addEmpleoyeeFinal(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    envio = new LinkedDouble<Employee>();
    if (envio->findInfo(id) == NULL) {
        envio->addNodeLast(Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}

bool
Management::addEmployeBeginTo(std::string name, std::string lastName, std::string charge, std::string id, short age,
                              std::string idBeginTo) {
    envio = new LinkedDouble<Employee>();
    if (envio->findInfo(idBeginTo) != NULL && envio->findInfo(id) == NULL) {
        envio->addNodeBeforeTo(envio->findNode(idBeginTo), Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}

bool
Management::addEmployeAfterTo(std::string name, std::string lastName, std::string charge, std::string id, short age,
                              std::string idAfterTo) {
    envio = new LinkedDouble<Employee>();
    if (envio->findInfo(idAfterTo) != NULL && envio->findInfo(id) == NULL) {
        envio->addNodeBeforeTo(envio->findNode(idAfterTo), Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}

bool
Management::addEmployeeSorted(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    envio = new LinkedDouble<Employee>();
    if (envio->findInfo(id) == NULL) {
        envio->addNodeFirst(Employee(name, lastName, charge, id, age));
        return true;
    }
    return false;
}

std::string Management::findEmployee(std::string id) {
    if (envio->findInfo(id) != NULL) {
        return "Si existe";
    } else {
        return "no existe";
    }

}

bool Management::deleteEmployee(std::string id) {
    if (envio->findInfo(id) != NULL){
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
    } else{
        std::cout<<"esta vacia";
    }
}

int Management::contEmployee() {
    if (envio->getSize()>0){
        return envio->getSize();
    }else{
        return -25;
    }

}

void Management::getFirst() {
    std::cout<<envio->getFirst();
}

void Management::getLast() {
    std::cout<<envio->getLast();
}












