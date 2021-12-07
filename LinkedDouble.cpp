//
// Created by Binmex on 04/12/2021.
//
/**
 * @author binmex
 */

#include "LinkedDouble.h"

/**
 * @brief metodo constructor, se inicializa la cabeza y la cola como null por buenas practicas
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 */
template<class T>
LinkedDouble<T>::LinkedDouble() {
    head = last = NULL;
}

/**
 * @brief metodo en el que indica que la lista esta vacia, ya que tanto la cabeza como la cola estan nulos
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @return retorna la cabeza y la cola de la lista nulas
 */
template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

/**
 * @brief metodo que añade un nodo al principio de la lista
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param info variable generica que indica la informacion a guardar en la lista
 */
template<class T>
void LinkedDouble<T>::addNodeFirst(T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = last = nodeNew;
    } else {
        head->previous = nodeNew;
        nodeNew->next = head;
        head = nodeNew;
    }
}

/**
 * @brief metodo que añade un nodo al final de la lista
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param info variable generica que indica la informacion a guardar en la lista
 */
template<class T>
void LinkedDouble<T>::addNodeLast(T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = last = nodeNew;
    } else {
        last->next = nodeNew;
        nodeNew->previous = last;
        last = nodeNew;
    }
}

/**
 * @brief metodo que añade nodos de manera ordenada con el principio alfa numericos
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param info variable generica que indica la informacion a guardar en la lista
 */
template<class T>
void LinkedDouble<T>::addNodeSorted(T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);

    if (isEmpty()) {
        head = last = nodeNew;
    } else if (info.getId().compare(head->info.getId()) < 0) {
        addNodeFirst(info);
    } else if (info.getId().compare(last->info.getId()) > 0) {
        addNodeLast(info);
    } else {
        NodeDouble<T> *act = head;
        NodeDouble<T> *ant = NULL;
        while (info.getId().compare(act->info.getId()) > 0) {
            ant = act;
            act = act->next;
        }
        nodeNew->next = act;
        nodeNew->previous = ant;
        ant->next = nodeNew;
        act->previous = nodeNew;
    }
}

/**
 * @brief metodo que buscaun nodo determinado con la key ID
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param id variable string que indica la key del empleado a buscar en la lista
 * @return retorna un apuntador con la posicionde memoria donde esta ubicado el empleado encontrado
 */
template<class T>
NodeDouble<T> *LinkedDouble<T>::findNode(std::string id) {
    NodeDouble<T> *aux = head;
    while (aux != NULL && aux->info.getId().compare(id) != 0) {
        aux = aux->next;
    }
    return aux;
}

/**
 * @brief metodo que busca la informacion pertinente a nodo determinado con la key ID
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param id variable string que indica la key del empleado a buscar en la lista
 * @return retorna la direccion de memoria con la informacion del empleado
 */
template<class T>
T *LinkedDouble<T>::findInfo(std::string id) {
    NodeDouble<T> *aux = head;
    while (aux != NULL) {
        if (aux->info.getId().compare(id) == 0)
            return &aux->info;
    }
    return NULL;
}

/**
 * @brief metodo que añade un nodo atras de otro definido por el usuario
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param before apuntador al nodo al que hace referencia para agregar el nuevo atras de este
 * @param info variable generica que indica la informacion a guardar en la lista
 */
template<class T>
void LinkedDouble<T>::addNodeBeforeTo(NodeDouble<T> *before, T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if (before == head) {
        addNodeFirst(info);
    } else {
        nodeNew->next = before;
        nodeNew->previous = before->previous;
        before->previous->next = nodeNew;
        before->previous = nodeNew;
    }
}
/**
 * @brief metodo que añade un nodo despues de otro definido por el usuario
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param after apuntador al nodo al que hace referencia para agregar el nuevo despues de este
 * @param info variable generica que indica la informacion a guardar en la lista
 */
template<class T>
void LinkedDouble<T>::addNodeAfterTo(NodeDouble<T> *after, T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if (after == last) {
        addNodeLast(info);
    } else {
        nodeNew->next = after->next;
        nodeNew->previous = after;
        after->next = nodeNew;
        after->next->previous = nodeNew;
    }
}

/**
 * @brief metodo que obtiene toda la lista con sus respectivos nodos
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param sw boolean que indica la manera de recorrer la lista true de alente paa atras, false de atras para adelante
 * @return retorna un vector con la informacion de la lista
 */
template<class T>
std::vector<T> LinkedDouble<T>::getList(bool sw) {
    std::vector<T> out;

    NodeDouble<T> *aux = sw ? head : last;

    while (aux != NULL) {
        out.push_back(aux->info);
        aux = sw ? aux->next : aux->previous;
    }

    return out;
}

/**
 * @brief metodo qye obtiene la cabeza de la lista
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @return retorna una variable generica con la informacion de la cabeza de la lista
 */
template<class T>
T LinkedDouble<T>::getFirst() {
    T info = head->info;
    return info;
}

/**
 * @brief metodo que obtine el tamaño de la lista, es decir el numero de nodos de la lista
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @return retorna un int con la cantidad de nodos de la lista
 */
template<class T>
int LinkedDouble<T>::getSize() {
    int cont = 0;
    NodeDouble<T> *aux = head;
    while (aux != NULL) {
        cont++;
        aux = aux->next;
    }

    return cont;
}

/**
 * @brief metodo que busca un nodo por medio del indice
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param index int que indica el indice de la lista
 * @return
 */
template<class T>
T *LinkedDouble<T>::getObject(int index) {
    NodeDouble<T> *aux = head;
    int cont = 0;
    while (cont < index) {
        aux = aux->next;
        cont++;
    }

    return &aux->info;
}

/**
 * @brief metodo destructor de la clase
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 */
template<class T>
LinkedDouble<T>::~LinkedDouble() {
    NodeDouble<T> *aux;
    while (head != NULL) {
        aux = head;
        head = head->next;
        delete (aux);
    }
}

/**
 * @brief metodo que retorna la cola de la lista
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @return retorna una variable generica con la informacion de la cola de la lista
 */
template<class T>
T LinkedDouble<T>::getLast() {
    T info = last->info;
    return info;
}

/**
 * @brief metodo que elimina un nodo indicado por el usuario identificado por la Key o id
 * @tparam T variable de tipo template en la que establece el tipo de clase generica a usar
 * @param node variable apuntador hacia el nodo que se desea eliminar
 * @return retorna una variable generica con la informacion del nodo de la lista
 */
template<class T>
T LinkedDouble<T>::deleteNode(NodeDouble<T> *node) {
    T info = node->info;
    NodeDouble<T> *ant = NULL;

    if (node == head && node->next == NULL) {
        head = NULL;
        last = NULL;

    } else {

        if (node == head) {
            head = head->next;
            head->previous = NULL;

        } else if (node == last) {
            last = last->previous;
            last->next = NULL;
        } else {
            NodeDouble<T> *aux = head;

            while (aux->next != node) {
                aux = aux->next;

            }
            aux->next = node->next;
            ant = node->next;
            ant->previous = aux;
        }
    }
    delete (node);
    return info;
}