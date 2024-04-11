#pragma once
#include <iostream>
using namespace std;

template<class T>
class DLNode {
private:
	T value;
	DLNode<T>* previous;
	DLNode<T>* next;

public:
	DLNode(T value, DLNode<T>* previous, DLNode<T>* next) {
		this->value = value;
		this->previous = previous;
		this->next = next;
	}

	int getValue() { return value; }
	DLNode<T>* getPrevious() { return previous; }
	DLNode<T>*& getPreviousRef() { return previous; }
	DLNode<T>* getNext() { return next; }
	DLNode<T>*& getNextRef() { return next; }
};
