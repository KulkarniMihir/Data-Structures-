/*
 * friend_node.cpp
 *
 *  Created on: 05-Mar-2020
 *      Author: f9
 */
#include "user.h"
#include <stack>
#include <queue>
#include <iomanip>

Facebook::Facebook() {
	// TODO Auto-generated constructor stub
	head = NULL;
}

Facebook::~Facebook() {
	// TODO Auto-generated destructor stub
}

static int count = 0;

friend_node* newfriend_node()		// allocates memory and takes data for new friend_node node
{
	friend_node *temp = new friend_node;
	count += 1;
	temp -> id = count;
	cout << "Name: ";
	cin.ignore();
	getline(cin,temp -> name);
	cout << "Date of Birth (DDMMYYYY):\nDay: ";
	cin >> temp -> date.day;
	cout << "Month: ";
	cin >> temp -> date.month;
	cout << "Year: ";
	cin >> temp -> date.year;
	temp -> down = NULL;
	temp -> nextlink = NULL;
	return temp;
}

comment_node* newFriend()		// allocates memory and takes data for new friend node
{
	comment_node *temp = new comment_node;
	cout << "Friend ID: ";
	cin >> temp -> id;
	cout << "No. of Comments on Friend's Posts: ";
	cin >> temp -> comments;
	temp -> nextcomment = NULL;
	return temp;
}

void Facebook::createGraph()
{
	if(head != NULL)
	{
		count = 0;
		for(friend_node *temp = head;temp != NULL;temp = temp -> down)
		{
			head = head -> down;
			delete temp;
		}
	}
	int n_friends,n_friend_nodes;
	cout << "\nNo. of friend_nodes: ";
	cin >> n_friend_nodes;
	for(int i = 0;i < n_friend_nodes;i++)
	{
		cout << "\nfriend_node #" << i + 1 << "\n";
		friend_node *temp = newfriend_node();
		cout << "No. of Friends: ";
		cin >> n_friends;

		for(int j = 0;j < n_friends;j++)
		{
			cout << "\nFriend #" << j + 1 << ":\n";
			comment_node *frnd = newFriend();
			if(temp -> nextlink == NULL)	// if no friends have been inserted yet
				temp -> nextlink = frnd;
			else
			{
				comment_node *temp1 = temp -> nextlink;
				while(temp1 -> nextcomment != NULL)	// iterate till last friend has been reached
					temp1 = temp1 -> nextcomment;
				temp1 -> nextcomment = frnd;	// insert new friend at last position
			}
		}
		if(head == NULL)	// if no friend_node has been added yet
			head = temp;
		else
		{
			friend_node *temp1 = head;
			while(temp1 -> down != NULL)	// iterate till latest friend_node has been reached
				temp1 = temp1 -> down;
			temp1 -> down = temp;	// insert at end
		}
	}

	// now, store addresses of friend_node nodes in the comment_node nodes

	for(friend_node *temp = head;temp != NULL;temp = temp -> down)	// each friend_node node
	{
		for(comment_node *frnd = temp -> nextlink;frnd != NULL;frnd = frnd -> nextcomment)	// each comment_node node
		{
			for(friend_node *temp = head;temp != NULL;temp = temp -> down)	// search address of node
			{
				if(frnd -> id == temp -> id)
					frnd ->comment_by = temp;
			}
		}
	}
}

void Facebook::displayUsers()
{
	cout << "friend_node ID" << setw(10) << "Name" << setw(27) << "comment_node | Comments\n";
	for(friend_node *temp = head;temp != NULL;temp = temp ->down)
	{
		cout << endl  << setw(4) << temp -> id << setw(15) <<  temp -> name << setw(6);
		for(comment_node *temp1 = temp -> nextlink; temp1 != NULL;temp1 = temp1 -> nextcomment)
			(temp1 -> nextcomment == NULL) ? (cout << temp1 -> id << " | " << temp1 -> comments) :(cout << temp1 -> id << " | " << temp1 -> comments << " -> ");
	}
	cout << endl;
}

void displaySinglefriend_node(friend_node* u)
{
	cout << endl  << setw(4) << u -> id << setw(15) <<  u -> name << setw(6);
	for(comment_node *temp1 = u ->nextlink; temp1 != NULL;temp1 = temp1 ->nextcomment)
		(temp1 -> nextcomment  == NULL) ? (cout << temp1 -> id << " | " << temp1 -> comments) :(cout << temp1 -> id << " | " << temp1 -> comments << " -> ");
}

void Facebook::birthdayMonth(int month)
{
	queue <friend_node*> q;
	int visited[count] = {0};	// array to store whether friend_node node has been visited
	q.push(head);
	cout << "friend_node ID" << setw(10) << "Name" << setw(27) << "comment_node | Comments\n";
	while(!q.empty())
	{
		friend_node *v = q.front();
		q.pop();
		visited[v -> id - 1] = 1;	// set given friend_node node has been visited
		for(comment_node *temp = v ->nextlink;temp != NULL;temp = temp ->nextcomment)
		{
			if(!visited[temp -> id - 1])	// if friend_node node has not been visited, push to queue
				q.push(temp ->comment_by);
		}
		if(v -> date.month == month)
			displaySinglefriend_node(v);
	}
	cout << endl;
}

int Facebook::DFS(const int p)		// single DFS function for maximum comments && friends
{
	stack <friend_node*> s;
	int visited[count] = {0};
	s.push(head);
	int globalmax = 0,localmax = -1;
	while(!s.empty())
	{
		friend_node *v = s.top();
		s.pop();
		visited[v -> id - 1] = 1;
		if(p == 1)	// reset local maximum in case of maximum comments
			localmax = 0;
		for(comment_node *temp = v ->nextlink;temp != NULL;temp = temp ->nextcomment)
		{
			if(!visited[temp -> id - 1])
				s.push(temp ->comment_by);
			switch(p)
			{
				case 1: localmax += 1;
						break;
				case 2: if(temp -> comments > globalmax)
							globalmax = temp -> comments;
						break;
			}
		}
		if(p == 1 && localmax > globalmax)	// update globalmax
			globalmax = localmax;
	}
	return globalmax;
}

int Facebook::minCommentsBFS()
{
	queue <friend_node*> q;
	int visited[count] = {0};
	q.push(head);
	int min = 1000;
	while(!q.empty())
	{
		friend_node *v = q.front();
		q.pop();
		visited[v -> id - 1] = 1;
		for(comment_node *temp = v ->nextlink;temp != NULL;temp = temp ->nextcomment)
		{
			if(temp -> comments < min)
				min = temp -> comments;
			if(!visited[temp -> id - 1])
				q.push(temp -> comment_by);
		}
	}
	return min;
}
