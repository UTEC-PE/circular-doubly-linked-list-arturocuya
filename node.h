#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(): next(nullptr), prev(nullptr){};
    Node(T argData): next(nullptr), prev(nullptr), data(argData){};

    void killSelf(Node<T> *start) {
    	if (next && next != start) {
    		next->killSelf(start);
    	}
    	delete this;
    };
    void print_next();
};

#endif
