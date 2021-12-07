//
// Created by Binmex on 04/12/2021.
//

/**
 * @author binmex
 */

#include "Management.h"
#include "LinkedDouble.cpp"
#include <iostream>

LinkedDouble<Employee> *envio = new LinkedDouble<Employee>();;

/**
 *@brief Metodo que añade un empleado al principio de la lista, realiza una validacion en la que verifica que no se encuentre un ID repetido,
 * si esto se cumple agrega el empleado al primcipio de la lista
 * @param name string que serequiere con el nombre del empleado
 * @param lastName string que se requiere con el apellido del empleado
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

/**
 * @brief Metodo que añade un empleado al final de la lista, realiza una validacion en la que verifica que no se encuentre un ID repetido,
 * si esto se cumple agrega el empleado al final de la lista
 * @param name string que serequiere con el nombre del empleado
 * @param lastName string que se requiere con el apellido del empleado
 * @param charge string que se requiere con el cargo del empleado
 * @param id string que requiere con el ID del empleado
 * @param age short que requiere la edad del empleado
 * @return retorna un boleano true si añade el empleado en caso contrario retorna un false
 */
bool Management::addEmpleoyeeFinal(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    if (envio->findNode(id) == NULL) {
        envio->addNodeLast(Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Metodo que añade un empleado detras de otro, realiza una validacion en la que verifica que no se encuentre un ID repetido
 * ,de igualmanera realiza una verificacion en la que comprueba que el empleado de referencia para posicionarlo si exista
 * si esto se cumple agrega el empleado detras del indicado por el usuario
 * @param name string que serequiere con el nombre del empleado
 * @param lastName string que se requiere con el apellido del empleado
 * @param charge string que se requiere con el cargo del empleado
 * @param id string que requiere con el ID del empleado
 * @param age short que requiere la edad del empleado
 * @param idBeginTo  string que requiere con el ID del empleado referencia para realizar la busqueda del nodo al que corresponde
 * @return  retorna un boleano true si añade el empleado en caso contrario retorna un false
 */
bool Management::addEmployeBeginTo(std::string name, std::string lastName, std::string charge, std::string id, short age,
                              std::string idBeginTo) {
    if (envio->findNode(idBeginTo) != NULL && envio->findNode(id) == NULL) {
        envio->addNodeBeforeTo(envio->findNode(idBeginTo), Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}
/**
 * @brief Metodo que añade un empleado despues de otro, realiza una validacion en la que verifica que no se encuentre un ID repetido
 * ,de igualmanera realiza una verificacion en la que comprueba que el empleado de referencia para posicionarlo si exista
 * si esto se cumple agrega el empleado despues del indicado por el usuario
 * @param name string que serequiere con el nombre del empleado
 * @param lastName string que se requiere con el apellido del empleado
 * @param charge string que se requiere con el cargo del empleado
 * @param id string que requiere con el ID del empleado
 * @param age short que requiere la edad del empleado
 * @param idAfterTo string que requiere con el ID del empleado referencia para realizar la busqueda del nodo al que corresponde
 * @return retorna un boleano true si añade el empleado en caso contrario retorna un false
 */
bool Management::addEmployeAfterTo(std::string name, std::string lastName, std::string charge, std::string id, short age,
                              std::string idAfterTo) {
    if (envio->findNode(idAfterTo) != NULL && envio->findNode(id) == NULL) {
        envio->addNodeBeforeTo(envio->findNode(idAfterTo), Employee(name, lastName, charge, id, age));
        return true;
    } else {
        return false;
    }
}
/**
 * @brief Metodo que añade un empleado despues de otro de manera ordenada, realiza una validacion en la que verifica que no se encuentre un ID repetido
 * ,si esto se cumple agrega el empleado con un orden alfanumerico
 * @param name string que serequiere con el nombre del empleado
 * @param lastName string que se requiere con el apellido del empleado
 * @param charge string que se requiere con el cargo del empleado
 * @param id string que requiere con el ID del empleado
 * @param age short que requiere la edad del empleado
 * @return un boolean con la informacion true(si se añade el empleado) y false en el caso contrario
 */
bool Management::addEmployeeSorted(std::string name, std::string lastName, std::string charge, std::string id, short age) {
    if (envio->findNode(id) == NULL) {
        envio->addNodeSorted(Employee(name, lastName, charge, id, age));
        return true;
    }
    return false;
}

/**
 * @brief Metodo que realiza una busqueda del empleado mediante el id del empleado
 * @param id  string que requiere con el ID del empleado
 * @return retorna un string con la informacion del empleado en el caso de ser encontrado, en caso contrario
 * retorna un "no existe"
 */
std::string Management::findEmployee(std::string id) {
    if (envio->findInfo(id) != NULL) {
        return "Nombre: " + envio->findInfo(id)->getName() + " Apellido: " + envio->findInfo(id)->getLastName()
               + " Cargo: " + envio->findInfo(id)->getCharge() + "ID: " + envio->findInfo(id)->getId()
               + " Edad: " + std::to_string(envio->findInfo(id)->getAge());
    } else {
        return "no existe";
    }

}

/**
 * @brief Metodo que elimina el nodo que hace referencia a un empleado, realizando una busqueda con el id que llega por
 * parametros
 * @param id string que requiere con el ID del empleado
 * @return rertorna un booleano true en caso de ser encontrado el empleado y eliminado, en caso contrario retorna un false
 */
bool Management::deleteEmployee(std::string id) {
    if (envio->findNode(id) != NULL) {
        envio->deleteNode(envio->findNode(id));
        return true;
    }
    return false;
}

/**
 * @brief metodo que lista toda la lista de empleados haciendo uso de un for mejorado
 */
void Management::listEmployee() {
    if (contEmployee() > 0) {
        for (Employee empleados: envio->getList(true)) {
            std::cout << "\n" << empleados << "\n";
        }
    } else {
        std::cout << "esta vacia";
    }
}

/**
 * @brief metodo que cuenta la cantidad de empleados que hay en la lista
 * @return retorna in int en caso de encontrar datos en la lista, en caso contrario retorna un int con valor de 0
 */
int Management::contEmployee() {
    if (envio->getSize() > 0) {
        return envio->getSize();
    } else {
        return 0;
    }

}

/**
 * @brief metodo que retorna la cabeza de la lista
 * @return retorna un string con la informacion del empleado
 */
std::string Management::getFirst() {
    return " Nombre: " + envio->getFirst().getName() + " Apellido: " + envio->getFirst().getLastName() + "Cargo: " +
           envio->getFirst().getCharge()
           + " ID: " + envio->getFirst().getId() + " Edad: " + std::to_string(envio->getFirst().getAge());
}

/**
 * @brief metodo que retorna la cola de la lista
 * @return retorna un string con la informacion del empleado
 */
std::string Management::getLast() {
    return " Nombre: " + envio->getLast().getName() + " Apellido: " + envio->getLast().getLastName() + "Cargo: " +
           envio->getLast().getCharge()
           + " ID: " + envio->getLast().getId() + " Edad: " + std::to_string(envio->getLast().getAge());
}













