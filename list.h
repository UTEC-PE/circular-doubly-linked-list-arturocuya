#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template<typename T>
class List {
private:
    Node<T> *start;
    int nodes = 0;
public:
    List() : start(nullptr) {};

    T front() {
        return start->data;
    };

    T back() {
        return start->prev->data;
    };

    void push_front(T value) {
        Node<T> *newNode = new Node<T>(value);
        if(!start) {
            start = newNode;
            newNode->next = start;
            newNode->prev = start;
        } else {
            Node<T> *Tmp = start->prev;
            Tmp->prev = newNode;
            newNode->next = Tmp;
            newNode->prev = start;
            start->prev = newNode;
            start->next = Tmp->prev;
            start = newNode;
        }
        nodes++;
    };

    void push_back(T value);

    void pop_front();

    void pop_back();

    T get(int position);

    void concat(List<T> &other);

    bool empty();

    int size() {
        return nodes;
    };

    void clear();

    Iterator<T> begin() {
        return start;
    };

    Iterator<T> end();

    ~List();
};

#endif