//============================================================================
// Name        : a2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<cstring>
using namespace std;
#include "sll.h"

int main()
{
	sll s;
	int choice;
	do
	{
		cout<<"\n***PATIENT APPOINTMENT***";
		cout<<"\n1.ENTER PATIENT DETAILS\n2.DELETE PATIENT DETAILS\n3.DISPLAY APPOINTMENTS\n0.EXIT";
		cout<<"\nEnter your choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				s.insert();
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.display();
				break;
			case 0:
				cout<<"\n***PROGRAM CLOSED***\n";
				break;
			default:
				cout<<"\nInvalid entry ! Re-enter :-";
		}
	}while(choice!=0);
	return 0;
};
