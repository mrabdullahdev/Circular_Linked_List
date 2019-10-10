#include <iostream>
#include "CircularList.h"

using namespace std;

// perametric constructor 
CircularList::CircularList(int num)
{
	Node* newNode = new Node();
	newNode->setValue(num);
	currentNode = newNode;
	size++;
}

// perametric Constructor
CircularList::CircularList(Node* newNode)
{
	currentNode = newNode;
	currentNode->setNextNode(0);
	currentNode->setPrevNode(0);
	size++;
}


// function for inserting new Node in the List
void CircularList::insertNode(int num)
{
	Node* newNode = new Node();
	newNode->setValue(num);
	if (size == 0)	// when List is previously empty
	{
		newNode->setNextNode(0);
		newNode->setPrevNode(0);
		currentNode = newNode;
		size++;
		exit;
	}
	else if (size == 1)	// in case List has only One Node
	{
		newNode->setPrevNode(currentNode);
		newNode->setNextNode(currentNode);
		currentNode->setPrevNode(newNode);
		currentNode->setNextNode(newNode);
		currentNode = newNode;
		size++;
		exit;
	}
	// this else will work when List has more than one Nodes
	else
	{
		newNode->setPrevNode(currentNode);
		newNode->setNextNode(currentNode->getNextNode());
		currentNode->getNextNode()->setPrevNode(newNode);
		currentNode->setNextNode(newNode);
		currentNode = newNode;
		size++;
		exit;
	}
	
	
}

// function for inserting new Node before specific Node
void CircularList::insertBefore(int dNum, int num)
{
	int f = 0;	// flag
	for (int i = 0; i < size; i++)	// loop for moving across List
	{
		if (dNum == currentNode->getValue())	// when Node is found
		{
			f = 1;
			CircularList::moveBackward();
			CircularList::insertNode(num);	// calling insertNode() function
			break;
		}
		CircularList::moveForward();
	}
	if(f==0)
		cout << "Number you entered does not match any value from the List.\n";
	else
		cout << "New Node is added successfully before " << dNum << " in the List.\n";
}

// function for inserting new Node after specific Node
void CircularList::insertAfter(int dNum, int num)
{
	int f = 0;	//flag
	for (int i = 0; i < size; i++)	// loop for moving across List
	{
		if (dNum == currentNode->getValue())	// when Node is found
		{
			CircularList::insertNode(num);	// calling insertNode() function
			f = 1;
			break;
		}
		CircularList::moveForward();
	}
	if (f == 0)
		cout << "Number you entered does not match any value from the List.\n";
	else
		cout << "New Node is added successfully after " << dNum << " in the List.\n";
}

// function for deleting specific Node
void CircularList::deleteNode(int num)
{
	int f = 0;	// flag
	for (int i = 0; i < size; i++)	// loop for moving across List
	{
		if (num == currentNode->getValue())	// when Node is found
		{
			f = 1;
			Node* newNode = new Node();
			newNode = currentNode;
			if (size == 1)	// when List has only one Node
			{
				CircularList::CircularList();
			}
			else if (size == 2)	// when List has two Nodes
			{
				CircularList::moveForward();
				currentNode->setNextNode(0);
				currentNode->setPrevNode(0);
				size--;
			}
			// this else will work when List has more than 2 Nodes
			else
			{
				currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());
				currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
				CircularList::moveForward();
				size--;
			}
			delete newNode;	// deleting newNode
			break;
		}
		CircularList::moveForward();
	}
	if (f == 0)
		cout << "Number you entered does not match any value from the List.\n";
	else
		cout << "Node with value " << num << " is successfully deleted from the List.\n";

}

// function for moving current Node to next Node
void CircularList::moveForward()
{
	currentNode = currentNode->getNextNode();
}

// function for moving current Node to previous Node
void CircularList::moveBackward()
{
	currentNode = currentNode->getPrevNode();
}

// function for checking if specific Node is present in the List
bool CircularList::searchValue(int num)
{
	for (int i = 0; i < size; i++)
	{
		if (currentNode->getValue() == num)	// case Node is found
			return true;
		CircularList::moveForward();
	}
	return false;
}

// function for returning value of current Node
int CircularList::get()
{
	int num;
	num = (*currentNode).getValue();
	return num;
}

// function for returning size of List
int CircularList::getSize()
{
	return size;
}

// function for Adding Nodes of List
int CircularList::sumOfNodes()
{
	int sum = 0;
	if (size == 0)	// case List is Empty
	{
		cout << "List is Empty\n";
	}
	// when List is not Empty
	else
	{
		for (int i = 0; i < size; i++)
		{
			sum += currentNode->getValue();
			CircularList::moveForward();
		}
	}
	return sum;
}

// function for Displaying Nodes of List
void CircularList::displayList()
{
	if (size == 0)
	{
		cout << "List is Empty.\n";
	}
	else
	{
		Node* ptr = new Node(0);
		ptr = currentNode;
		cout << "Values of Nodes of List are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << ptr->getValue() << endl;
			ptr = ptr->getNextNode();
		}
	}
}
