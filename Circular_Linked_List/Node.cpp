#include "Node.h"

void Node::setValue(int num)
{
	value = num;
}

void Node::setNextNode(Node* newNode)
{
	next = newNode;
}

int Node::getValue()
{
	return value;
}

Node* Node::getNextNode()
{
	return next;
}
