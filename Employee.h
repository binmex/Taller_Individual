//
// Created by Binmex on 04/12/2021.
//

#ifndef TALLER_INDIVIDUAL_EMPLOYEE_H
#define TALLER_INDIVIDUAL_EMPLOYEE_H
#include <string>
#include <ostream>

class Employee {
public:
    Employee();

    Employee(const std::string &name, const std::string &lastName, const std::string &charge, const std::string &id,
             short age);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getCharge() const;

    void setCharge(const std::string &charge);

    const std::string &getId() const;

    void setId(const std::string &id);

    short getAge() const;

    void setAge(short age);



    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);

    virtual ~Employee();

private:
    std::string Name;
    std::string LastName;
    std::string charge;
    std::string id;
    short age;

};


#endif //TALLER_INDIVIDUAL_EMPLOYEE_H
