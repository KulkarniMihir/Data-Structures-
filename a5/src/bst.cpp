/*
 * bst.cpp
 *
 *  Created on: 17-Feb-2020
 *      Author: f9
 */

#include "bst.h"
#include "bits/stdc++.h"
using namespace std;

bst::bst()
{
	root = NULL;
}

int bst::isEmpty()
{
	if(root == NULL)
		return 1;
	return 0;
}

node *bst::getRoot()
{
	return root;
}

int bst::searchNode(node *Tnode,int info)
{
	int depth = 0;
	node *temp = new node;
	temp = root;
	while(temp != NULL)
	{
		depth++;
	    if(temp->data == info)
	      {
	         cout<<"\nData found at depth: "<<depth<<endl;
	         return 0;
	      }
	      else if(temp->data > info)
	      temp = temp->left;
	      else
	      temp = temp->right;
	   }
	   cout<<"\n Data not found"<<endl;
	   return 0;
}

void bst::insert()
{
	node *current = new node;
	cout<<"\nEnter value to be inserted : ";
	cin>>current->data;
	root = insertNode(getRoot(),current);
}

node *bst::insertNode(node *Tnode,node *current)
{
	if(isEmpty())
	{
		root=current;
		//root->data = current->data;
		current->left = NULL;
		current->right = NULL;
		return root;
	}
	if(root->data == current->data)
	{
		cout<<"\nNode already exits";
	}

	else if(Tnode->data > current->data)
	{
		if(Tnode->left != NULL)
		{
			insertNode(Tnode->left,current);
		}
		else
		{
			Tnode->left = current;
			Tnode->left->left = NULL;
			Tnode->left->right = NULL;
			cout<<"\nROOT ADDED TO LEFT"<<"\n";
		}
	}
	else
	{
		if(Tnode->right != NULL)
		{
			Tnode->right = insertNode(Tnode->right,current);
		}
		else
		{
			Tnode->right = current;
			Tnode->right->left = NULL;
			Tnode->right->right = NULL;
			cout<<"\nROOT ADDED TO LEFT"<<"\n";
		}
	}
	return root;
}

void bst::display(node *Tnode)
{
	if(Tnode != NULL)
	{
		display(Tnode->left);
		cout<<setw(3)<<Tnode->data;
		display(Tnode->right);
	}
	if(isEmpty())
		cout<<"\nTree is empty."<<endl;
}

