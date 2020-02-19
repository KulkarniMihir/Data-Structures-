/*
 * tree.h
 *
 *  Created on: 10-Feb-2020
 *      Author: f9
 */

#include "stack.h"

#ifndef TREE_H_
#define TREE_H_

class tree
{
	Tnode *root;
public:
	tree();
	virtual ~tree();
	Tnode* newNode(char);
	Tnode* getRoot();
	void createTree(char[]);
	void RecursivePreOrder(Tnode*);
	void RecursivePostOrder(Tnode*);
	void RecursiveInOrder(Tnode*);
	void NonRecursivePreOrder(Tnode*);
	void NonRecursivePostOrder(Tnode*);
	void NonRecursiveInOrder(Tnode*);
};

#endif /* TREE_H_ */
