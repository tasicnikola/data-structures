#pragma once
#include <iostream>
using namespace std;

template<class T>
class SLNode {
protected:
	T value;
	SLNode<T>* next;
public:
	SLNode() {
		this->value = (T)0;
		next = nullptr;
	}

	SLNode(T value) {
		this->value = value;
		next = nullptr;
	}
	
	SLNode(T& value, SLNode<T>* next) {
		this->value = value;
		this->next = next;
	}
	
	~SLNode() {}
	T getValue() { return value; }
	T* getValueRef() { return &value; }
	SLNode<T>* getNext() { return next; }	
	SLNode<T>*& getNextRef() { return next; }

	void setValue(const T& val) {
		value = val;
	}

	void setNext(SLNode<T>* nextNode) {
		next = nextNode;
	}
};
