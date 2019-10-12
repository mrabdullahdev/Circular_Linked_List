#include <iostream>
#include "CircularList.h"

using namespace std;

// perametric constructor 
CircularList::CircularList(int num)
{
	Node* newNode = new Node();
	newNode->setValue(num);
	headNode = currentNode = newNode;
	size++;
}

// perametric Constructor
CircularList::CircularList(Node* newNode)
{
	headNode = currentNode = newNode;
	currentNode->setNextNode(currentNode);
	currentNode->setPrevNode(currentNode);
	size++;
}


// function for inserting new Node in the List
void CircularList::insertNode(int num)
{
	Node* newNode = new Node();
	if (size == 0)	// when List is previously empty
	{
		newNode->setNextNode(newNode);
		newNode->setPrevNode(newNode);
		headNode = newNode;
	}
	else
	{
		newNode->setPrevNode(currentNode);
		newNode->setNextNode(currentNode->getNextNode());
		currentNode->getNextNode()->setPrevNode(newNode);
		currentNode->setNextNode(newNode);
	}
	currentNode = newNode;
	currentNode->setValue(num);
	size++;
}
// function to insert Node in the Begining
void CircularList::insertAtBegin(int num)
{
	Node* newNode = new Node();
	CircularList::end();
	newNode->setNextNode(headNode);
	newNode->setPrevNode(currentNode);
	newNode->setValue(num);
	if (size != 0)
	{
		headNode->getPrevNode()->setNextNode(newNode);
		headNode->setPrevNode(newNode);
	}
	headNode = currentNode = newNode;
	size++;
}
// function to insert Node in the Begining
void CircularList::insertAtEnd(int num)
{
	CircularList::end();
	CircularList::insertNode(num);
}
// function to insert Node at specific index
void CircularList::insertTo(int num, int position)
{
	if (position > (size + 1))
		cout << "Index is out of bound.\n";
	else
	{
		CircularList::start();
		for (int i = 2; i < position; i++)
		{
			CircularList::moveForward();
		}
		CircularList::insertNode(num);
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
			if (currentNode == headNode)
			{
				CircularList::moveBackward();
				CircularList::insertNode(num);	// calling insertNode() function
				headNode = headNode->getPrevNode();
			}
			else
			{
				CircularList::moveBackward();
				CircularList::insertNode(num);	// calling insertNode() function
			}
			
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
			f = 1;
			CircularList::insertNode(num);	// calling insertNode() function
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
			else
			{
				currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());
				currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
				CircularList::moveForward();
				if (newNode == headNode)	// when deleting first Node
				{
					headNode = currentNode;
				}
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

// fuction for moving current Node to head Node
void CircularList::start()
{
	currentNode = headNode;
}
// function for moving current Node to last Node
void CircularList::end()
{
	currentNode = headNode->getPrevNode();
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
		ptr = headNode;
		cout << "Values of Nodes of List are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << ptr->getValue() << endl;
			ptr = ptr->getNextNode();
		}
	}
}
// function for sorting List in ascending order
void CircularList::ascendingSortingOfList()
{
	int temp;
	CircularList::start();
	Node* ptr = new Node;
	for (int i = 0; i < size; i++)
	{
		ptr = currentNode->getNextNode();
		for (int j = i + 1; j < size; j++)
		{
			if (currentNode->getValue() > ptr->getValue())
			{
				temp = currentNode->getValue();
				currentNode->setValue(ptr->getValue());
				ptr->setValue(temp);
			}
			ptr = ptr->getNextNode();
		}
		CircularList::moveForward();
	}
}

// function for sorting Nodes of List in descending order
void CircularList::descendingSortingOfList()
{
	int temp;
	CircularList::start();
	Node* ptr = new Node;
	for (int i = 0; i < size; i++)
	{
		ptr = currentNode->getNextNode();
		for (int j = i + 1; j < size; j++)
		{
			if (currentNode->getValue() < ptr->getValue())
			{
				temp = currentNode->getValue();
				currentNode->setValue(ptr->getValue());
				ptr->setValue(temp);
			}
			ptr = ptr->getNextNode();
		}
		CircularList::moveForward();
	}
}

// function for reversing Nodes of List
void CircularList::revertingList()
{
	Node* ptr;
	ptr = headNode;
	int dSize = size / 2;
	int temp;
	CircularList::end();

	for (int i = 0; i < dSize; i++)
	{
		temp = currentNode->getValue();
		currentNode->setValue(ptr->getValue());
		ptr->setValue(temp);
		CircularList::moveBackward();
		ptr = ptr->getNextNode();
	}
	CircularList::start();
}

// Destructor
CircularList::~CircularList()
{
	for (int i = 0; i < size; i++)
	{
		Node* newNode = new Node();
		newNode = currentNode;
		delete newNode;
		CircularList::moveForward();
	}
}