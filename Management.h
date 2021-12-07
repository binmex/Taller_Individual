//
// Created by Binmex on 04/12/2021.
//

#ifndef TALLER_INDIVIDUAL_MANAGEMENT_H
#define TALLER_INDIVIDUAL_MANAGEMENT_H
#include <string>
#include "Employee.h"

class Management {
public:
    bool addEmpleoyee(std::string,std::string,std::string,std::string,short );
    bool addEmpleoyeeFinal(std::string,std::string,std::string,std::string,short);
    bool addEmployeBeginTo(std::string,std::string,std::string,std::string,short,std::string);
    bool addEmployeAfterTo(std::string,std::string,std::string,std::string,short,std::string);
    bool addEmployeeSorted(std::string,std::string,std::string,std::string,short);
    std::string findEmployee(std::string);
    bool deleteEmployee(std::string);
    void listEmployee();
    int contEmployee();
    void getFirst();
    void getLast();


private:

};


#endif //TALLER_INDIVIDUAL_MANAGEMENT_H
