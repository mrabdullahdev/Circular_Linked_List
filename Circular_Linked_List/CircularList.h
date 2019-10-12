#pragma once
#include "Node.h"
class CircularList
{
private:// private members
	Node* headNode;
	Node* currentNode;
	int size;
public:// public members
	// constructors
	CircularList():headNode(0),currentNode(0),size(0){}
	CircularList(int num);
	CircularList(Node* newNode);
	// functions for adding Nodes
	void insertNode(int num);
	void insertAtBegin(int num);
	void insertAtEnd(int num);
	void insertTo(int num, int position);
	void insertBefore(int dNum, int num);
	void insertAfter(int dNum, int num);
	// function for deleting Node
	void deleteNode(int num);
	// functions for moving current Node
	void start();
	void end();
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

	void ascendingSortingOfList();
	void descendingSortingOfList();
	void revertingList();

	// Destructor
	~CircularList();

};

