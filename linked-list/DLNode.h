#pragma once
#include "SLNode.h"

class DLNode {
private:
	int value;
	DLNode* previous;
	DLNode* next;

public:
	DLNode(int value, DLNode* previous, DLNode* next) {
		this->value = value;
		this->previous = previous;
		this->next = next;
	}

	int getValue() { return value; }
	DLNode* getPrevious() { return previous; }
	DLNode*& getPreviousRef() { return previous; }
	DLNode* getNext() { return next; }
	DLNode*& getNextRef() { return next; }
};
