/*
 * stk.cpp
 *
 *  Created on: 19-Dec-2019
 *      Author: f9
 */
#include "iostream"
using namespace std;

#include "stk.h"

stk::stk() {
	// TODO Auto-generated constructor stub
top='\0';
}

 stk::~stk() {
	// TODO Auto-generated destructor stub
}

node::node()
{
	data=0;
	next='\0';
}

void stk::push(char x)
{
	node *p;
	p=new node;
	p->data=x;
	p->next=top;
	top=p;
}

int stk::pop()
{
	if(!empty())
	      {
	          node *p;
	         // p=new node;
	          p=top;
	          top=top->next;
	          x=p->data;
	          delete p;
	          return(x);
	     }
	      else
	      {
	           //cout<<"stack is empty"<<endl;
	           return(0);
	      }

}

void stk::display()
{
	node *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\n";
		temp=temp->next;

	}
}

int stk::peek()
{
	 if(!empty())
	 {
	     node *p;
	     p=new node;
	     p=top;
	     x=p->data;
	     return(x);
      }
      else
      {
          //cout<<"stack is empty"<<endl;
          return(0);
	  }
}


int stk::empty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
