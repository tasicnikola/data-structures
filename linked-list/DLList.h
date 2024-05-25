#pragma once
#include "DLNode.h"

template <class T>
class DLList {
private:
	DLNode<T>* head;
	DLNode<T>* tail;

public:
	DLList() { head = tail = nullptr; }	
	~DLList() { while (!isEmpty()) removeFromHead(); }
	bool isEmpty() { return head == nullptr; }
	DLNode<T>* getHead() { return head; }
	DLNode<T>* getTail() { return tail; }

	void print() {
		DLNode<T>* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->getPrevious() << "|" << ptr->getValue() << "|" << ptr->getNext() << " -> ";
			ptr = ptr->getNext();
		}
	}

	DLNode<T>* find(int value) {
		DLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != value) {
			ptr = ptr->getNext();
		}

		return ptr;
	}

	void insertHead(int value) {
		DLNode<T>* node = new DLNode(value, nullptr, head);
		if (!head)
			tail = node;
		else
			head->getPreviousRef() = node;
		head = node;
	}

	void insertTail(int value) {
		DLNode<T>* node = new DLNode(value, tail, nullptr);
		if (!tail)
			head = node;
		else
			tail->getNextRef() = node;
		tail = node;
	}

	void remove(int value) {
		if (head == nullptr)
			throw ("Empty list");

		DLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != value) {
			ptr = ptr->getNext();
		}

		if (head == tail && head->getValue() == value) {
			head = tail = nullptr;
		}
		else if (head->getValue() == value) {
			head = ptr->getNext();
			ptr->getPreviousRef() == nullptr;
		}
		else {
			if (ptr != nullptr) {
				ptr->getPrevious()->getNextRef() = ptr->getNext();

				if (ptr == tail)
					tail = ptr->getPrevious();
				else
					ptr->getNext()->getPreviousRef() = ptr->getPrevious();
			}
			else
				throw exception("Element not found");
		}
	}

	void removeFromHead() {
		if (!head)
			throw exception("Empty list");
		else {
			DLNode<T>* ptr = head;
			if (head == tail)
				head = tail = nullptr;
			else {
				head = head->getNext();
				head->getPreviousRef() == nullptr;
			}

			delete ptr;
		}
	}

	void removeFromTail() {
		if (!head)
			throw exception("Empty list");
		else {
			DLNode<T>* ptr = tail->getPrevious();
			DLNode<T>* tmp = tail;
			if (tail == head)
				head = tail = nullptr;
			else {
				ptr->getNextRef() == nullptr;
				tail = ptr;
			}

			delete ptr;
		}
	}

	//Write a function void MovePartToEnd(int val1, int val2) that extracts a sequence of nodes from a doubly linked list between the nodes with values val1 and val2 and moves it to the end of the list.
	//Node values in the linked list are unique.
	//Assume that nodes with values val1and val2 exist in the listand that the node with the value val2 is not ahead of the node with the value val1.
	void movePartToEnd(T val1, T val2) {
		bool border = true;
		DLNode<T>* ptr1 = nullptr, * ptr2 = nullptr;
		DLNode<T>* ptr = head;

		while ((ptr1 == nullptr || ptr2 == nullptr) && ptr != nullptr) {
			if (ptr->value == val1) {
				ptr1 = ptr;
				if (ptr2 != nullptr) {
					border = false;
				}
			}
			if (ptr->value == val2) {
				ptr2 = ptr;
			}
			ptr = ptr->next;
		}

		if (ptr1 == nullptr || ptr2 == nullptr)
			return;

		if (!border) {
			DLNode<T>* ptrSwap = ptr1;
			ptr1 = ptr2;
			ptr2 = ptrSwap;
		}

		if (ptr2 == tail)
			return;

		if (ptr1->previous == nullptr) {
			head = ptr2->next;
		}
		else {
			ptr1->prev->next = ptr2->next;
		}
		ptr2->next->prev = ptr1->prev;

		tail->next = ptr1;
		ptr1->prev = tail;
		ptr2->next = nullptr;
		tail = ptr2;
	}


};
