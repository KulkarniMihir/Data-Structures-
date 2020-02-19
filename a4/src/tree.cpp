/*
 * tree.cpp
 *
 *  Created on: 10-Feb-2020
 *      Author: f9
 */
#include<iostream>
//#include<stdlib.h>
//#include<cstring>
//#include<string>
#include<bits/stdc++.h>
using namespace std;
#include "tree.h"

tree::tree() {
	root=NULL;
	// TODO Auto-generated constructor stub

}

tree::~tree() {
	// TODO Auto-generated destructor stub
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

Tnode* tree::newNode(char n)
{
	Tnode *temp = new Tnode;
	temp->right=temp->left='\0';
	temp->info=n;
	return temp;
}

Tnode* tree::getRoot()
{
	return root;
}

void tree::createTree(char exp[])
{
	if(!isOperator(exp[0]))	// Check if post-fix
	{
		Stack st;
		Tnode *t, *t1, *t2;
		for(int i = 0;i < strlen(exp);i++)		// Traverse through every character of input expression
		{
			if (!isOperator(exp[i]))	// If operand, push to stack
			{
				t = newNode(exp[i]);
				st.push(t);
			}
			else // operator
			{
				t = newNode(exp[i]);

				// Pop two top nodes
				t1 = st.pop();
				t2 = st.pop();

				//  make them children
				t -> right = t1;
				t -> left = t2;

				st.push(t);	// Add this subexpression to stack
			}
		}
		root = st.pop();	//  only element will be root of expression tree
		cout << "\nTree created Successfully!\n";
	}
	else
	{
		Stack st;
		Tnode *t, *t1, *t2;
		reverse(exp,exp + strlen(exp));
		for(int i = 0;i < strlen(exp);i++)		// Traverse through every character of input expression
		{
			if (!isOperator(exp[i]))	// If operand, push to stack
			{
				t = newNode(exp[i]);
				st.push(t);
			}
			else // operator
			{
				t = newNode(exp[i]);
				// Pop two top nodes
				t1 = st.pop();
				t2 = st.pop();

				//  make them children
				t -> left = t1;
				t -> right = t2;

				st.push(t);	// Add this subexpression to stack
			}
		}
		root = st.pop();	//  only element will be root of expression tree
		cout << "\nTree created Successfully!\n";
	}

}

void tree::RecursivePreOrder(Tnode *T)
{
	if(T != NULL)
	{
		cout << T -> info;
		RecursivePreOrder(T -> left);
		RecursivePreOrder(T -> right);
	}
}

void tree::RecursivePostOrder(Tnode *T)
{
	if(T != NULL)
	{
		RecursivePreOrder(T -> left);
		RecursivePreOrder(T -> right);
		cout << T -> info;
	}
}

void tree::RecursiveInOrder(Tnode *T)
{
	if(T != NULL)
	{
		RecursivePreOrder(T -> left);
		cout << T -> info;
		RecursivePreOrder(T -> right);
	}
}



void tree::NonRecursivePreOrder(Tnode *T)
{
	if(T == NULL)
	{
		cout << "\nTree is Empty.\n";
		return;
	}
	Stack s;
	s.push(T);
	do
	{
		Tnode *p = s.pop();
		while(p != NULL)
		{
			cout << p -> info;
			if(p -> right != NULL)
				s.push(p -> right);
			p = p -> left;
		}
	}while(!s.isempty());
}

void tree::NonRecursivePostOrder(Tnode *T)
{
	Stack s;
	Tnode *p = T;
	s.push(T);
	while(!s.isempty() && T != NULL)
	{
		T = s.peep();
		if((T -> left == NULL && T -> right == NULL) || (p == T -> left || p == T -> right))
		{
			// nodes without children should be printed
			//or nodes whose children have already been printed
			cout << T -> info;
			s.pop();
			p = T;
		}
		else
		{
			if(T -> right != NULL) s.push(T -> right);
			if(T -> left != NULL) s.push(T -> left);
		}
	}
}

void tree::NonRecursiveInOrder(Tnode *T)
{
	Stack s;
	while (T != NULL || !s.isempty())
	{
		while (T !=  NULL)	// Reach the left most Node
		{
			s.push(T);
			T = T -> left;
		}
		T = s.pop();		 // T must be NULL at this point
		cout << T -> info;
		T = T -> right;		// Visited left subtree and node; now visit right
	}
}


