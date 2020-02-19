/*
 * stack.cpp
 *
 *  Created on: 10-Feb-2020
 *      Author: f9
 */

#include "stack.h"

Stack::Stack() {
	top = '\0';
	// TODO Auto-generated constructor stub

}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

bool Stack::isempty()
{
	if(top=='\0')
		return 1;
	else
		return 0;
}

void Stack::push(Tnode *x)
{
	Snode *p = new Snode;
	p -> data = x;
	p->next=top;
	top=p;
}

Tnode * Stack::pop()
{
	Tnode *returnNode = top -> data;
	Snode  *topNode;
	topNode = top;
	top = top -> next;
	delete topNode;
	return returnNode;
}

Tnode* Stack::peep()
{
	return top->data;
}
