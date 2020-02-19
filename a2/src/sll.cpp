/*
 * sll.cpp
 *
 *  Created on: 06-Jan-2020
 *      Author: f9
 */
#include<iostream>
#include<string>
#include "sll.h"
using namespace std;

sll::sll() {
	// TODO Auto-generated constructor stub
	front='\0';
	rear='\0';
	temp='\0';
}

sll::~sll() {
	// TODO Auto-generated destructor stub
}

node::node()
{
	next='\0';
	patientno='0';
}

int sll::isempty()
{
	if(front=='\0')
		return 1;
	else
		return 0;
}

void sll::insert()
{
	//node *temp;
	node *p = new node;
	cout<<"\nEnter Patient number :";
	cin>>p->patientno;
	cout<<"\nEnter Category of Patient :-";
	cout<<"\n1.General Checkup\n2.Not Serious\n3.Serious : \n=> ";
	cin>>p->priority;
	p->next=NULL;

	if(isempty())
	{
		front=p;
		rear=p;
	}
	if(front==rear)
	{
		if(p->priority > front->priority)
		{
			p->next=rear;
			front=p;
		}
		if(p->priority <= rear->priority)
		{
			front->next=p;
			rear=rear->next;
		}
	}

	else
	{

		if(p->priority > front->priority)
		{
			p->next=front;
			front=p;
		}

		else if(p->priority <= rear->priority)
			{
				rear->next=p;
				rear=rear->next;
				p=rear;
			}
			else
			{
				temp=front;
				while(p->priority <= temp->next->priority && temp->next != NULL)
				{
					temp=temp->next;
				}
				p->next = temp->next;
				temp->next=p;

			}


		/*while(p->priority <= temp->next->priority && temp->next != NULL)
		{
			temp=temp->next;
		}
		if(p->priority <= temp->next->priority)
		{
			p->next=temp->next;
			temp->next=p;
			return;
		}
		if(temp==rear)
		{
			p=front->next;
			rear=p;
		}*/
	}

}

void sll::pop()
{
	//node *temp;
	if(!isempty())
	{
		temp=front;
		front=front->next;
		delete(temp);
		//return(temp->patientno);
	}
	else
		cout<<"\nNo Patients !";
}

int sll::peekfront()
{
	if(!isempty())
		return(front->patientno);
	else
	{
		cout<<"\nNo Patients in queue !";
		return(0);
	}
}

int sll::peekrear()
{
	if(!isempty())
			return(rear->patientno);
	else
	{
		cout<<"\nNo Patients in queue !";

		return(0);
	}
}

void sll::display()
{
	char ans;
	char Y,N;
	temp=front;
	if(isempty())
	{
		cout<<"\nNo Patients in Queue !";
		cout<<"\nDo You have a New Patient (Y/N): "<<"\n";
		cin>>ans;
		if('Y'== ans)
			insert();
		else
			cout<<"\n***Program Closed***\n";
	}
	if(temp == rear)
	{
		cout<<temp->patientno<<"\t";
		cout<<temp->priority<<"\n";
	}
	else
	{
		while(temp != rear)
		{
			cout<<temp->patientno<<"\t";
			cout<<temp->priority<<"\n";
			temp=temp->next;
			if(temp == rear)
				{
					cout<<temp->patientno<<"\t";
					cout<<temp->priority<<"\n";
				}
		}
	}
}
