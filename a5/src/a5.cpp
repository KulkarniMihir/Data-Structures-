//============================================================================
// Name        : a5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include "bst.h"
using namespace std;


int main()
{
	bst t;
	int choice;
	int key;

	do
	{
		cout<<"\n*****BINARY SEARCH TREE*****\n1)Insert node\n2)Delete node\n3)Display tree\n4)Search for a node\n5)Create mirror image\n6)Display level-wise\n7)Exit"<<endl;
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"\n***INSERTION***\n";
			t.insert();
			break;
		case 3:
			cout<<"\n***DISPLAY INORDER***\n";
			cout<<"\n"<<t.getRoot()->data;
			t.display(t.getRoot());
			break;
		case 4:
			cout<<"\n***SEARCH NODE***\n";
			cout<<"\nEnter value to search : ";
			cin>>key;
			t.searchNode(t.getRoot(),key);
			break;
		case 7:
			exit(0);
		}
	}while(1);

	return 0;
}
