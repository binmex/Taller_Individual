//
// Created by Binmex on 04/12/2021.
//
/**
 * @brief clase del objeto empleado, en el que se indican los set y los gets de sus atributos
 */

#include "Employee.h"

Employee::Employee(const std::string &name, const std::string &lastName, const std::string &charge,
                   const std::string &id, short age) : Name(name), LastName(lastName), charge(charge), id(id),
                                                       age(age) {}

const std::string &Employee::getName() const {
    return Name;
}

void Employee::setName(const std::string &name) {
    Name = name;
}

const std::string &Employee::getLastName() const {
    return LastName;
}

void Employee::setLastName(const std::string &lastName) {
    LastName = lastName;
}

const std::string &Employee::getCharge() const {
    return charge;
}

void Employee::setCharge(const std::string &charge) {
    Employee::charge = charge;
}

const std::string &Employee::getId() const {
    return id;
}

void Employee::setId(const std::string &id) {
    Employee::id = id;
}

short Employee::getAge() const {
    return age;
}

void Employee::setAge(short age) {
    Employee::age = age;
}


std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    os << "Name: " << employee.Name << " LastName: " << employee.LastName << " charge: " << employee.charge << " id: "
       << employee.id << " age: " << employee.age;
    return os;
}

Employee::~Employee() {

}