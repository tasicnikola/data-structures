#pragma once
#include <iostream>
#include "GraphEdge.h"
using namespace std;

class GraphNode {
private:
	GraphNode* next;
	GraphEdge* edges;
	int value;
	int status;

public:
	GraphNode(int val) : value(val), edges(nullptr), status(0), next(nullptr) {}
	GraphNode(int val, GraphNode* next) : value(val), next(next), edges(nullptr), status(0) {}
	int getValue() { return value; }
	GraphNode* getNext() { return next; }
	GraphEdge* getEdges() { return edges; }
	GraphEdge*& getEdgesRef() { return edges; }
	int getStatus() { return status; }
	void setStatus(int s) : status(s) {}
};