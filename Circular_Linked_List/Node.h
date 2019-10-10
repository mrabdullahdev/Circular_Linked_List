#pragma once
// Node class
class Node
{
private:// private members
	int value;
	Node* nextNode;
	Node* prevNode;
public:// public members
	// Constructors
	Node():value(0),nextNode(0),prevNode(0){}
	Node(int num):value(num),nextNode(0),prevNode(0){}
	// functions for setting values
	void setValue(int num);
	void setNextNode(Node* newNode);
	void setPrevNode(Node* newNode);
	// functions for getting values
	int getValue();
	Node* getNextNode();
	Node* getPrevNode();

};

