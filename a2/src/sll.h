/*
 * sll.h
 *
 *  Created on: 06-Jan-2020
 *      Author: f9
 */

#ifndef SLL_H_
#define SLL_H_

class node
{
	public:
		node *next;
		int priority;
		int patientno;
		node();
};

class sll {
	node *front,*rear;
public:
	node *temp;
	sll();
	virtual ~sll();
	int isempty();
	void insert();
	void pop();
	int peekfront();
	int peekrear();
	void display();

};

#endif /* SLL_H_ */
