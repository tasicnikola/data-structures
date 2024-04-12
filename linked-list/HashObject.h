#pragma once
#include <iostream>
using namespace std;

template <class T, class R>
class HashObject {
protected:
	T key;
	R record;

public:
	HashObject() { key = record = NULL; }
	HashObject(T key) { this->key = key; record = NULL; }
	HashObject(T key, R record) { this->key = key; this->record = record; }
	~HashObject() { deleteRecord(); }
	void deleteRecord() { if (record) { delete record; record = NULL; } }
	T getKey() { return key; }
	R getRecord() { return record; }
	bool isEqualKey(T key) { return this->key == key; }
	void print() { cout << key << "|" << record; }
};
