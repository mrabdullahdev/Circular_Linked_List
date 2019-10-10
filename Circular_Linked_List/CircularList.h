#pragma once
#include "Node.h"
class CircularList
{
private:// private members
	Node* currentNode;
	int size;
public:// public members
	// constructors
	CircularList():currentNode(0),size(0){}
	CircularList(int num);
	CircularList(Node* newNode);
	// functions for adding Nodes
	void insertNode(int num);
	void insertBefore(int dNum, int num);
	void insertAfter(int dNum, int num);
	// function for deleting Node
	void deleteNode(int num);
	// functions for moving current Node
	void moveForward();
	void moveBackward();
	// function for searching value
	bool searchValue(int num);
	// functions for geting members
	int get();
	int getSize();
	// function for adding Nodes
	int sumOfNodes();
	// function for displaying Nodes
	void displayList();
};

