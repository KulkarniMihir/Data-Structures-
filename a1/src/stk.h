/*
 * stk.h
 *
 *  Created on: 19-Dec-2019
 *      Author: f9
 */

#ifndef STK_H_
#define STK_H_

class node
{
public:
     char data;
     node *next;
     node();
};

class stk
{
	node *top;
	char x;
public:
	stk();
	virtual ~stk();
	int empty();
	void push(char x);
	int pop();
	void display();
	int peek();

};

#endif /* STK_H_ */
