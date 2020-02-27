/*
 * graph.cpp
 *
 *  Created on: 24-Feb-2020
 *      Author: f9
 */
#include "iostream"
#include "stdlib.h"
#include "string"
#include "graph.h"
using namespace std;

graph::graph() {
	v=0;
	e=0;
	head = NULL;
	// TODO Auto-generated constructor stub

}

graph::~graph() {
	head=NULL;
	// TODO Auto-generated destructor stub
}

friend_node::friend_node()
{
	id=0;
	down='\0';
	d.date=0;
	d.month=0;
	d.year=0;
	next='\0';
}

relations::relations()
{
	comments=0;
	nxt='\0';
	comment_by = NULL;
}

void graph::insert()
{
	cout<<"\nEnter number of vertices :";
	cin>>v;
	for(int i=0;i<v;i++)
	{
		if(head =='\0')
		{
			friend_node *p = new friend_node;
			cout<<"\nEnter id :";
			cin>>p->id;
			cout<<"\nEnter DOB(dd/mm/yyyy) :";
			cin>>p->d.date;
			cin>>p->d.month;
			cin>>p->d.year;
			head=p;
		}
		else
		{
			friend_node *temp = head;
			while(temp->down != '\0')
				temp=temp->down;
			friend_node *p=new friend_node;
			cout<<"\nEnter id :";
			cin>>p->id;
			cout<<"\nEnter DOB(dd/mm/yyyy) :";
			cin>>p->d.date;
			cin>>p->d.month;
			cin>>p->d.year;
			temp->down=p;
		}
	}

	cout<<"\nEnter number of edges : ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		relations *r = new relations;
		relations *x;
		cout<<"\nEnter comments :";
		cin>>r->comments;
		int f1,f2;
		cout<<"\nEnter 1st friends id :";
		cin>>f1;
		cout<<"\nEnter 2nd friends id :";
		cin>>f2;
		friend_node *find,*find1;
		find=head;
		find1=head;
		while(find->id != f1)
		{
			find=find->down;
			if(find->next==NULL)
			{
				cout<<"\nNO FRIEND FOUND\n";
			}
		}
		if(find->next=='\0')
		{
			find->next=r;
			x=r;
		}
		else
		{
			while(x->nxt!= NULL)
			{
				x=x->nxt;
			}
			x->nxt=r;
			x=r;
		}
		while(find1->id != f2)
		{
			find1=find1->down;
			if(find1->next==NULL)
			{
				cout<<"\nNO FRIEND FOUND\n";
			}
		}
		r->comment_by=find1;
	}

}

void graph::display()
{
	queue< friend_node* > q;
}
