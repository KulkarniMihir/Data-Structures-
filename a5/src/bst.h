/*
 * bst.h
 *
 *  Created on: 17-Feb-2020
 *      Author: f9
 */

#ifndef BST_H_
#define BST_H_

class node
{
    public:
	int data;
	node *left;
	node *right;
};

class bst
{
	node *root;
    public:
    	bst();
    	int isEmpty();
    	node *getRoot();
    	int searchNode(node *Tnode,int info);
    	node *insertNode(node *Tnode,node *current);
    	void insert();
    	void deleteNode(node *Tnode);
    	node *mirrorImage();
    	void display(node *Tnode);
    	void displayLevel(node *Tnode);
};

#endif /* BST_H_ */
