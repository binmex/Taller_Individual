//
// Created by Binmex on 04/12/2021.
//

#ifndef TALLER_INDIVIDUAL_LINKEDDOUBLE_H
#define TALLER_INDIVIDUAL_LINKEDDOUBLE_H

#include <vector>
#include "NodeDouble.h"
#include <string>

template<class T>
class LinkedDouble {
public:
    LinkedDouble();

    bool isEmpty();

    void addNodeFirst(T);

    void addNodeLast(T);

    void addNodeSorted(T);

    NodeDouble<T> *findNode(std::string);

    T *findInfo(std::string);

    void addNodeBeforeTo(NodeDouble<T> *, T);

    void addNodeAfterTo(NodeDouble<T> *, T);

    std::vector<T> getList(bool);

    int getSize();

    T *getObject(int);

    T deleteNode(NodeDouble<T> *);

    T getFirst();

    T getLast();

    virtual ~LinkedDouble();

private:
    NodeDouble<T> *head;
    NodeDouble<T> *last;
};

#endif //TALLER_INDIVIDUAL_LINKEDDOUBLE_H
