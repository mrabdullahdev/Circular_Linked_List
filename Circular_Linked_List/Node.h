#pragma once
// Node class
class Node
{
private:// private members
	int value;
	Node* next;
public:// public members
	// Constructors
	Node():value(0),next(0){}
	Node(int num):value(num),next(0){}
	// functions for setting values
	void setValue(int num);
	void setNextNode(Node* newNode);
	// functions for getting values
	int getValue();
	Node* getNextNode();

};

