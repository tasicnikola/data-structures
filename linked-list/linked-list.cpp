#include <iostream>
#include "SLList.h"

int main()
{
	SLList<int> list;

	list.insertHead(9);
	list.insertHead(13);
	list.insertTail(8);
	list.insertTail(7);

	list.insertAfter(4, 7);
	list.insertBefore(5, 4);
	list.insertHead(10);

	list.swap(10, 13);
	list.fillInTheBlanks();

	list.printList();
}
