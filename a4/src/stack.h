/*
 * stack.h
 *
 *  Created on: 10-Feb-2020
 *      Author: f9
 */

#ifndef STACK_H_
#define STACK_H_

struct Tnode
{
	char info;
	struct Tnode *left;
	struct Tnode *right;
};

struct Snode
{
	Tnode *data;
	Snode *next;
};

class Stack
{
	Snode *top;
public:
	Stack();
	virtual ~Stack();
	Tnode * pop();
	void push(Tnode *);
	Tnode* peep();
	bool isempty();
};

#endif /* STACK_H_ */
