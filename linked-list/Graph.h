#pragma once
#include <iostream>
#include "GraphNode.h"
#include "GraphEdge.h"

class Graph {
private:
	GraphNode* start;
	unsigned int numberOfNodes;

public:
	Graph() : start(nullptr), numberOfNodes(0) {}

	/*
		void BFS(int a) {
		queue<GraphNode*> q;
		int visited = 0;
		GraphEdge* e;
		GraphNode* ptr = start;

		while (ptr) {
			ptr->setStatus(1); //ready 
			ptr = ptr->getNext();
		}

		ptr = findNode(a);
		if (!ptr)
			return;
		q.push(ptr);
		ptr->setStatus(2);
		while (!q.empty()) {
			ptr = q.front();
			q.pop();
			ptr->setStatus(3);
			cout << ptr->getValue() << endl;
			e = ptr->adj;
			while (e) {
				if (e->getDestination()->getStatus() == 1) {
					e->getDestination()->setStatus(2);
					q.push(e->getDestination());
				}
				e = e->getNext();
			}
		}
	}
	*/

	void insertNode(int val) {
		GraphNode* newNode = new GraphNode(val, start);
		start = newNode;
		numberOfNodes++;
	}

	GraphNode* findNode(int val) {
		GraphNode* ptr = start;
		while (ptr != nullptr && ptr->getValue() != val)
			ptr = ptr->getNext();

		return ptr;
	}

	void insertEdge(int val1, int val2) {
		GraphNode* ptr = start;
		GraphNode* node1 = nullptr;
		GraphNode* node2 = nullptr;
		while (ptr != nullptr && (node1 == nullptr || node2 == nullptr)) {
			if (ptr->getValue() == val1)
				node1 = ptr;
			if (ptr->getValue() == val2)
				node2 = ptr;
			ptr = ptr->getNext();
		}

		if (node1 != nullptr && node2 != nullptr) {
			GraphEdge* temp = new GraphEdge(node1->getEdges(), node2);
			node1->getEdgesRef() = temp;
		}
	}

	GraphEdge* findEdge(int val1, int val2) {
		GraphNode* ptr = start;
		GraphNode* node1 = nullptr;
		GraphNode* node2 = nullptr;
		while (ptr != nullptr && (node1 == nullptr || node2 == nullptr)) {
			if (ptr->getValue() == val1)
				node1 = ptr;
			if (ptr->getValue() == val2)
				node2 = ptr;
			ptr = ptr->getNext();
		}
		if (node1 == nullptr || node2 == nullptr)
			return nullptr;

		GraphEdge* edge = node1->getEdges();
		while (edge != nullptr && edge->getDestination() != node2)
			edge = edge->getNext();
		
		return edge;
	}

	void print() {
		GraphNode* ptr = start;
		while (ptr != nullptr) {
			cout << ptr->getValue() << "->";
			GraphEdge* pa = ptr->getEdges();
			while (pa != NULL) {
				cout << pa->getDestination()->getValue() << " | ";
				pa = pa->getNext();
			}
			cout << "\r\n";
			ptr = ptr->getNext();
		}
	}

	unsigned int numberOfLoops() {
		GraphNode* ptr = start;
		unsigned int num = 0;
		while (ptr != nullptr) {
			GraphEdge* link = ptr->getEdges();
			while (link != nullptr && link->getDestination() != ptr)
				link = link->getNext();
			if (link != nullptr)
				num++;
			ptr = ptr->getNext();
		}

		return num;
	}


	void maxInDeg() {
		GraphNode* wantedNode = start;
		GraphNode* maxPtr = NULL;
		int max = INT_MIN;

		while (wantedNode) {
			int num = 0;
			GraphNode* ptr = start;

			while (ptr) {
				GraphEdge* e = ptr->getEdges();
				while (e) {
					if (e->getDestination()->getValue() == wantedNode->getValue())
						num++;
					e = e->getNext();
				}
				ptr = ptr->getNext();
			}
			if (num > max) {
				max = num;
				maxPtr = wantedNode;
			}
			wantedNode = wantedNode->getNext();
		}

		if (maxPtr) {
			cout << "Node with max in degree: " << maxPtr->getValue() << "." << endl;
			cout << "Degree: " << max << endl;
		}
		else {
			cout << "There is no node with in degree." << endl;
		}
	}
	
	void maxOutDeg() {
		GraphNode* ptr = start;
		GraphNode* wantedNode = NULL;
		int max = INT_MIN;

		while (ptr) {
			int count = 0;
			GraphEdge* e = ptr->getEdges();
			while (e) {
				count++;
				e = e->getNext();
			}
			if (count > max) {
				max = count;
				wantedNode = ptr;
			}
			ptr = ptr->getNext();
		}
		if (wantedNode) {
			cout << "Max out degree: " << max << endl;
			cout << "On node: " << wantedNode->getValue() << endl;
		}

	}

	void adjescentMatrix() {
		GraphNode** niz = new GraphNode * [numberOfNodes];
		GraphNode* ptr = start;
		int i = 0;
		while (ptr) {
			niz[i] = ptr;
			i++;
			ptr = ptr->getNext();
		}

		int** matSusedstva = new int* [numberOfNodes];
		for (int i = 0; i < numberOfNodes; i++) {
			matSusedstva[i] = new int[numberOfNodes];
		}

		ptr = start;
		i = 0;
		while (ptr) {
			for (int j = 0; j < numberOfNodes; j++) {
				if (findEdge(ptr->getValue(), niz[j]->getValue()))
					matSusedstva[i][j] = 1;
				else 
					matSusedstva[i][j] = 0;
			}
			ptr = ptr->getNext();
			i++;
		}

		cout << "Matrica susedstva:\n";

		for (int i = 0; i < this->nodeNum; i++)
		{

			for (int j = 0; j < this->nodeNum; j++)
				cout << matSusedstva[i][j] << " ";

			cout << endl;
		}

		cout << endl << endl;
	}

	bool removeNode(int a) {
		GraphNode* nodeA = findNode(a);
		if (!nodeA)
			return false;

		GraphNode* ptr = start;
		while (ptr && ptr->getNext() && ptr->getNext() != nodeA)
			ptr = ptr->getNext();
		if (ptr && ptr->getNext() && ptr->getNext() == nodeA) {
			ptr->getNext() = nodeA->getNext();
		}

		ptr = start;
		while (ptr) {
			GraphEdge* e = ptr->getEdges();
			while (e) {
				if (e->getNext() && e->getNext()->getDestination() == nodeA)
					e->getNext() = e->getNext()->getNext();
				e = e->getNext();
			}
			ptr = ptr->getNext();
		}

		return true;
	}
};