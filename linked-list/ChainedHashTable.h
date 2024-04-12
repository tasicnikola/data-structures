#pragma once
#include "HashTable.h"
#include "SLList.h"

template<class T, class R>
class ChainedHashTable : public HashTable<T, R> {
protected:
	SLList<HashObject<T, R>>* niz;

public:
	ChainedHashTable() { HashTable<T, R>::lenght = 0; HashTable<T, R>::count = 0; }
	ChainedHashTable(int l) {
		HashTable<T, R>::lenght = l; HashTable<T, R>::count = 0;
	}
	~ChainedHashTable() {
		for (int i = 0; i < HashTable<T, R>::lenght; i++) {
			SLNode<HashObject<T, R>>* obj = niz[i].getHead();
			while (obj != nullptr) {
				((HashObject<T, R>)obj->getValue()).deleteRecord();
				obj = obj->getNext();
			}
		}
		delete[] niz;
	}

	void insert(HashObject<T, R> obj) {
		niz[HashTable<T, R>::h(obj)].insertHead(obj);
		HashTable<T, R>::count++;
	}

	void withdraw(T key) {
		HashObject<T, R> obj = find(key);
		withdraw(obj);
	}

	void withdraw(HashObject<T, R> obj) {
		niz[HashTable<T, R>::h(obj)].remove(obj.getKey());
		HashTable<T, R>::count--;
	}

	HashObject<T, R>& find(T key) {
		HashObject<T, R> obj;
		unsigned int i = HashTable<T, R>::f(key) % HashTable<T, R>::lenght;
		obj = niz[i].getHead()->getValue();
	}

	void print() {
		for (int i = 0; i < HashTable<T, R>::lenght; i++) {
			SLNode<HashTable<T, R>>* obj = niz[i].getHead();
			if (obj) {
				cout << obj->getValueRef()->getKey() << " | ";
				while (obj != nullptr) {
					cout << (obj->getValueRef()->getRecord()) << "->";
					obj = obj->getNext();
				}
			}
		}
	}
};
