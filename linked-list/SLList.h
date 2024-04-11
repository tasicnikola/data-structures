#pragma once
#include <stdexcept>
#include "SLNode.h"

template <class T>
class SLList {
private:
	SLNode<T>* head;
	SLNode<T>* tail;
public:
	SLList() { head = tail = nullptr; }
	~SLList() { while (!isEmpty()) removeFromHead(); }
	SLNode<T>* getHead() { return head; }
	SLNode<T>* getTail() { return tail; }

	bool isEmpty() {
		return head == nullptr;
	}

	void printList() {
		SLNode<T>* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->getValue();
			if (ptr->getNext() != nullptr) {
				cout << " -> ";
			}
			ptr = ptr->getNext();
		}
	}

	SLNode<T>* find(T value) {
		SLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != value) {
			ptr = ptr->getNext();
		}

		return ptr;
	}

	void insertHead(T value) {
		SLNode<T>* node = new SLNode<T>(value, head);
		if (!head)
			tail = node;
		head = node;
	}

	void insertTail(T value) {
		SLNode<T>* node = new SLNode<T>(value, nullptr);
		if (!tail)
			head = node;
		else
			tail->getNextRef() = node;
		tail = node;
	}

	void insertBefore(T value, T spot) {
		SLNode<T>* prev = nullptr;
		SLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != spot) {
			prev = ptr;
			ptr = ptr->getNext();
		}

		if (!ptr)
			cerr << "Error: Spot not found" << endl;
		else {
			SLNode<T>* node = new SLNode<T>(value, ptr);
			if (prev == nullptr)
				head = node;
			else
				prev->getNextRef() = node;
		}
	}

	void insertAfter(T value, T spot) {
		SLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != spot) {
			ptr = ptr->getNext();
		}

		if (ptr == nullptr)
			cerr << "Error: Spot not found" << endl;
		else
		{
			SLNode<T>* node = new SLNode<T>(value, ptr->getNext());
			ptr->getNextRef() = node;
			if (ptr == tail)
				tail = node;
		}
	}

	void remove(T value) {
		SLNode<T>* prev = nullptr;
		SLNode<T>* ptr = head;
		
		if (isEmpty())
			throw exception("Empty list");

		while (ptr != nullptr && ptr->getValue() != value) {
			prev = ptr;
			ptr = ptr->getNext();
		}

		if (head == tail && head->getValue() == value)
			head = tail = nullptr;
		else if (head->getValue() == value)
			head = head->getNext();
		else {
			if (ptr != nullptr) {
				prev->getNextRef() = ptr->getNext();
				if (ptr == tail)
					tail = prev;
			}
			else {
				throw exception("Element not found");
			}
		}

		delete ptr;
	}

	void removeFromHead() {
		if (!head)
			throw exception("The list is empty");
		else {
			SLNode<T>* ptr = head;
			if (tail == ptr)
				tail = nullptr;
			head = ptr->getNext();
			delete ptr;
		}
	}

	void removeFromTail() {
		if (!tail)
			throw exception("The list is empty");
		else
		{
			SLNode<T>* ptr = tail;
			if (head == tail)
			{
				tail = nullptr;
				head = nullptr;
			}
			else {
				SLNode<T>* tmp = head;
				while (tmp != nullptr && tmp->getNext() != tail) {
					tmp = tmp->getNext();
				}
				tail = tmp;
				tmp->getNextRef() = nullptr;
			}
			delete ptr;
		}
	}

	//Write a function void Swap(T val1, T val2) that swaps the positions of the element with value val1 and the element with value val2 in a singly linked list.
	//Values in the nodes of the linked list are unique.
	//Assume that nodes with values val1 and val2: exist in the list, are not adjacent, and the node with value val2 is not ahead of the node with value val1.
	void swap(T val1, T val2) {
		if (val1 == val2)
			return;

		SLNode<T>* prevX = nullptr;
		SLNode<T>* currX = head;
		while (currX && currX->getValue() != val1) {
			prevX = currX;
			currX = currX->getNext();
		}

		SLNode<T>* prevY = nullptr;
		SLNode<T>* currY = head;
		while (currY && currY->getValue() != val2) {
			prevY = currY;
			currY = currY->getNext();
		}

		if (currX == nullptr || currY == nullptr)
			return;

		if (prevX != nullptr)
			prevX->setNext(currY);
		else
			head = currY;

		if (prevY != nullptr)
			prevY->setNext(currX);
		else
			head = currX;

		SLNode<T>* temp = currY->getNext();
		currY->setNext(currX->getNext());
		currX->setNext(temp);
	};

	//Write a function void LList::fillInTheBlanks() that, from a dynamically implemented linked list where the info parts are integers ordered in non-descending order, removes all duplicate nodes and adds nodes for all those values that are missing between the values of two consecutive nodes in the list. For example, if the info parts of two consecutive nodes have values 1 and 4, it is necessary to add nodes with values 2 and 3 between them.
	void fillInTheBlanks() {
		if (head == nullptr || head->getNext() == nullptr)
			return;

		SLNode<T>* prev = head;
		SLNode<T>* ptr = head->getNext();
		SLNode<T>* nextNode;

		while (ptr != nullptr) {
			nextNode = ptr->getNext();
			if (prev->getValue() == ptr->getValue()) {
				prev->setNext(nextNode);
				delete ptr;
			}
			else if (ptr->getValue() - prev->getValue() > 1) {
				for (int i = 1; i < ptr->getValue() - prev->getValue(); ++i) {
					SLNode<T>* newNode = new SLNode<T>(prev->getValue() + i);
					newNode->setNext(ptr);
					prev->setNext(newNode);
					prev = newNode;
				}
			}
			else {
				prev = ptr;
			}
			ptr = nextNode;
		}
	}



};
