#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"
#include <cmath>

using namespace std;

template<typename T>
class List {
private:
    Node<T> *start;
    int nodes = 0;
public:
    List() : start(nullptr) {};

    T front() {
        if (start) return start->data;
        else throw runtime_error("Empty list");
    };

    T back() {
        if (start) return start->prev->data;
        else throw runtime_error("Empty list");
    };

    void push_front(T value) {
        Node<T> *newNode = new Node<T>(value);
        if(!start) {
            start = newNode;
            newNode->next = start;
            newNode->prev = start;
        } else {
    		Node<T> *after = start;
    		Node<T> *before = start->prev;

    		newNode->next = after;
    		newNode->prev = before;

    		after->prev = newNode;
    		before->next = newNode;		
        }
        start = newNode;
        nodes++;
    };

    void push_back(T value) {
        Node<T> *newNode = new Node<T>(value);
        if(!start) {
            start = newNode;
            newNode->next = start;
            newNode->prev = start;
        } else {
    		Node<T> *after = start;
    		Node<T> *before = start->prev;

    		newNode->next = after;
    		newNode->prev = before;

    		after->prev = newNode;
    		before->next = newNode;		
        }
        nodes++;
    };

    void pop_front() {
        if(start) {
            Node<T> *target = start;
            Node<T> *after = start->next;
            Node<T> *before = start->prev;

            delete target;
            
            start = after;
            after->prev = before;
            before->next = after;
            nodes--;
        } else {
            throw runtime_error("Empty list");
        }
    };

    void pop_back() {
        if (start) {
            Node<T> *target = start->prev;
            Node<T> *before = target->prev;

            delete target;

            before->next = start;
            start->prev = before;
            nodes--;
        } else {
            throw runtime_error("Empty list");
        }
    };

    T get(int position) {
        if (start) {
            Node<T> *r = start;
            for (int i = 0; i < abs(position); i++) {
                r = (position > 0) ? r->next : r->prev; 
            }
            return r->data;
        } else {
            throw runtime_error("Empty list");
        }
    };

    void concat(List<T> &other) {
        Node<T> *thisStart = start;
        Node<T> *thisLast = start->prev;
        Node<T> *otherStart = other.start;
        Node<T> *otherLast = other.start->prev;
        
        thisLast->next = otherStart;
        otherStart->prev = thisLast;

        otherLast->next = thisStart;
        thisStart->prev = otherLast;

        nodes += other.size();
    };

    bool empty(){
        return !start;
    };

    int size() {
        return nodes;
    };

    void clear() {
        if (start) {
            start->killSelf(start);
        }
        start = nullptr;
        nodes = 0;
    };

    Iterator<T> begin() {
        if (start) {
            Iterator<T> it = Iterator<T>(start);
            return it;
        } else {
            throw runtime_error("Empty list");
        }
    };

    Iterator<T> end() {
        if (start) {
            Iterator<T> it = Iterator<T>(start->prev);
            return it;  
        } else {
            throw runtime_error("Empty list");
        }
    };

    ~List(){
        clear();
    };
};

#endif
