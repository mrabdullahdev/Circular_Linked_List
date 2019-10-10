#include "Node.h"

// function for setting value of Node
void Node::setValue(int num)
{
	value = num;
}
// function for setting next pointer of Node
void Node::setNextNode(Node* newNode)
{
	nextNode = newNode;
}
// function for setting previous pointer of Node
void Node::setPrevNode(Node* newNode)
{
	prevNode = newNode;
}
// function for getting value of Node
int Node::getValue()
{
	return value;
}
// function for getting next pointer of Node
Node* Node::getNextNode()
{
	return nextNode;
}
// function for getting previous pointer of Node
Node* Node::getPrevNode()
{
	return prevNode;
}
