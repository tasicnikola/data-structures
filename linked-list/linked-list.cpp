#include <iostream>
#include "SLList.h"
#include "Graph.h"

int main()
{
	/*
		SLList<int> list1;

	list1.insertHead(9);
	list1.insertHead(13);
	list1.insertTail(8);
	list1.insertTail(7);

	list1.insertAfter(4, 7);
	list1.insertBefore(5, 4);
	list1.insertHead(10);
	//list1.printList();

	SLList<int> list4;
	list4.insertHead(39);
	list4.insertHead(21);
	list4.insertHead(16);
	list4.insertHead(17);
	list4.insertHead(12);
	list4.insertHead(8);

	list4.printList();

//	list.fillInTheBlanks();

	SLList<int> list2;
	list2.insertHead(22);
	list2.insertHead(20);
	list2.insertHead(15);
	list2.insertHead(11);
	list2.printList();

	SLList<int> list3;

	*/

	Graph graph1;
	graph1.insertNode(5);
	graph1.insertNode(11);
	graph1.insertNode(13);
	graph1.insertNode(15);
	graph1.insertNode(7);

	graph1.insertEdge(5, 11);
	graph1.insertEdge(11, 15);
	graph1.insertEdge(15, 7);
	graph1.insertEdge(13, 7);
	graph1.insertEdge(5, 7);
	graph1.insertEdge(7, 11);
	graph1.insertEdge(7, 15);
	graph1.insertEdge(7, 13);


	//graph1.print();
	graph1.maxInDeg();
	graph1.maxOutDeg();

} 
