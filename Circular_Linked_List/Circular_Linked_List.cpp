// Circular_Linked_List.cpp : This file contains the 'main' function.
// Program execution begins and ends there.
// 

#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
	// checking functionality of Node class 
	Node n1, n2(33);
	n1.setValue(12);
	n1.setNextNode(&n2);
	n2.setPrevNode(&n1);

	cout << "Node 1: " << n1.getValue() << endl;
	cout << "Node 2: " << n2.getValue() << endl;
	cout << "Printing Node 2 by using next pointer of Node 2: " << n1.getNextNode()->getValue() << endl;
	cout << "Printing Node 1 by using previous pointer of Node 2: " << n2.getPrevNode()->getValue() << endl;

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
