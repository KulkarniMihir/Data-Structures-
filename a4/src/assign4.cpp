//============================================================================
// Name        : assign4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "tree.h"


int main()
{
	tree t;
	char *inputExpression = new char[100];
	int choice;
	do
	{
		cout << "\nExpression Tree\n\n1. Input Expression\n2. Display Traversals\n0. Exit\nYour Choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
					cout << "Input PostFix / PreFix Expression: ";
					cin.ignore();
					cin >> inputExpression;
					t.createTree(inputExpression);
					break;
			case 2:
					cout << "\nRECURSIVE\n";\

					cout << "\nPreOrder: ";
					t.RecursivePreOrder(t.getRoot());
					cout << "\nInOrder: ";
					t.RecursiveInOrder(t.getRoot());
					cout << "\nPostOrder: ";
					t.RecursivePostOrder(t.getRoot());
					cout << "\n\nNON - RECURSIVE\n";
					cout << "\nPreOrder: "; t.NonRecursivePreOrder(t.getRoot());
					cout << "\nInOrder: "; t.NonRecursiveInOrder(t.getRoot());
					cout << "\nPostOrder: "; t.NonRecursivePostOrder(t.getRoot());

					break;
			case 0:
					cout<<"\n***PROGRAM CLOSED***\n";
					break;
			default: cout << "\nInvalid entry ! Re-enter :- \n";
		}
	}while(choice != 0);
	return 0;
}
