// Circular_Linked_List.cpp : This file contains the 'main' function.
// Program execution begins and ends there.
// 

#include <iostream>
#include "Node.h"
#include "CircularList.h"

using namespace std;

int main()
{
	// checking functionality of Node class *****************************************************************************
	Node n1, n2(33);
	n1.setValue(12);
	n1.setNextNode(&n2);
	n2.setPrevNode(&n1);
	// printing Node Values
	cout << "Node 1: " << endl << n1.getValue() << endl;	// printing n1
	cout << "Node 2: " << endl << n2.getValue() << endl;	// printing n1
	// printing n2 by using n1
	cout << "Printing Node 2 by using next pointer of Node 1: " << endl << n1.getNextNode()->getValue() << endl;
	// printing n1 by accessing n2
	cout << "Printing Node 2 by using previous pointer of Node 2: " << endl << n2.getPrevNode()->getValue() << endl;

	// checking functionality of CircularList class ********************************************************************
	CircularList c1;	// simple constructor
	CircularList c2(44);	// calling parametric construstor 
	CircularList c3(&n1);	// calling parametric constructor 
	c1.insertNode(30);	// insrting Node to the List c1

	// Displaying current Node of c1
	cout << "Printing current Node of c1:" << endl << c1.get() << endl;
	// Displaying current Node of c2
	cout << "Printing current Node of c2:" << endl << c2.get() << endl;
	// Displaying current Node of c3
	cout << "Printing current Node of c3:" << endl << c3.get() << endl;
	// inserting new Node in List c1
	c1.insertNode(89);	
	cout << "Printing current Node of c1 after adding new Node:" << endl << c1.get() << endl;
	c1.insertNode(77);	// inserting new Node in List c1
	cout << "Printing current Node of c1 after adding new Node:" << endl << c1.get() << endl;
	c1.moveBackward();	// moving current Node backward
	cout << "Printing current Node of c1 after moving current Node backward:" << endl << c1.get() << endl;
	c1.moveBackward();	// moving current Node backward
	cout << "Printing current Node of c1 after moving current Node backward:" << endl << c1.get() << endl;
	c1.insertNode(56);	// inserting new Node in List c1
	cout << "Printing current Node of c1 after adding new Node:" << endl << c1.get() << endl;
	c1.moveForward();
	cout << "Printing current Node of c1 after moving current Node forward:" << endl << c1.get() << endl;
	c1.insertBefore(56, 765);	// inserting new Node in List c1 after 56
	cout << "Printing current Node of c1 after adding new Node before 56:" << endl << c1.get() << endl;
	c1.insertAfter(89, 146);	// inserting new Node in List c1 before 89
	cout << "Printing current Node of c1 after adding new Node after 89:" << endl << c1.get() << endl;

	//  inserting Node at Begining
	c1.insertAtBegin(940);
	cout << "Displaying List after inserting Node at Begining from List:\n";
	c1.displayList();	// Displaying Nodes of List
	//  inserting Node at End
	c1.insertAtEnd(51);
	cout << "Displaying List after inserting Node at End from List:\n";
	c1.displayList();	// Displaying Nodes of List
	//  inserting Node at specific index
	c1.insertTo(435,5);
	cout << "Displaying List after inserting Node in 5th position from List:\n";
	c1.displayList();	// Displaying Nodes of List
	// Displaying Size of List c1
	cout << "Printing size of the List: " << endl << c1.getSize() << endl;
	c1.deleteNode(56);		// deleting specific Node from List c1
	cout << "Displaying List after deleting a Node from List:\n";
	c1.displayList();	// Displaying Nodes of List
	cout << "Printing size of the List: " << endl << c1.getSize() << endl;
	// Sorting Nodes
	cout << "Displaying Nodes of List after sorting them in Ascending order:\n";
	c1.ascendingSortingOfList();
	c1.displayList();

	c1.insertNode(395);	// inserting new Node in List c1
	cout << "Printing current Node of c1 after adding new Node:" << endl << c1.get() << endl;
	c1.insertNode(235);	// inserting new Node in List c1
	cout << "Printing current Node of c1 after adding new Node:" << endl << c1.get() << endl;
	cout << "Displaying List c1:\n";	// Displaying List c1
	c1.displayList();
	// descending sorting
	cout << "Displaying Nodes of List after sorting them in Descending order:\n";
	c1.descendingSortingOfList();
	c1.displayList();
	// Reversing Nodes
	cout << "Displaying Nodes of List after reversing them:\n";
	c1.revertingList();
	c1.displayList();

	// Displaying size of List c1
	cout << "Printing size of the List: " << endl << c1.getSize() << endl;
	// for searching specific value from List c1
	if (c1.searchValue(89))
	{
		cout << "Node is present.\n";
	}
	else
	{
		cout << "Not present\n";
	}
	// Displaying sum of Nodes of List c1
	cout << "Sum of Nodes: " << endl << c1.sumOfNodes();
	return 0;
	// Sorting Nodes
	cout << "Displaying Nodes of List after sorting them in Descending order:\n";
	c1.descendingSortingOfList();
	c1.displayList();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
