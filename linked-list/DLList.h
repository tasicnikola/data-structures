#pragma once
#include <DLNode.h>

class DLList {
private:
	DLNode* head;
	DLNode* tail;

public:
	DLList() { head = tail = nullptr; }	
	~DLList() { while (!isEmpty()) removeFromHead(); }
	bool isEmpty() { return head == nullptr; }
	DLNode* getHead() { return head; }
	DLNode* getTail() { return tail; }

	void print() {
		DLNode* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->getPrevious() << "|" << ptr->getValue() << "|" << ptr->getNext() << " -> ";
			ptr = ptr->getNext();
		}
	}

	DLNode* find(int value) {
		DLNode* ptr = head;
		while (ptr != nullptr && ptr->getValue() != value) {
			ptr = ptr->getNext();
		}

		return ptr;
	}

	void insertHead(int value) {
		DLNode* node = new DLNode(value, nullptr, head);
		if (!head)
			tail = node;
		else
			head->getPreviousRef() = node;
		head = node;
	}

	void insertTail(int value) {
		DLNode* node = new DLNode(value, tail, nullptr);
		if (!tail)
			head = node;
		else
			tail->getNextRef() = node;
		tail = node;
	}

	void insertBefore(int value, int spot) {

	}

	void remove(int value) {
		if (head == nullptr)
			throw exception("Empty list");

		DLNode* ptr = head;
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
			DLNode* ptr = head;
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
			DLNode* ptr = tail->getPrevious();
			DLNode* tmp = tail;
			if (tail == head)
				head = tail = nullptr;
			else {
				ptr->getNextRef() == nullptr;
				tail = ptr;
			}

			delete ptr;
		}
	}
};
