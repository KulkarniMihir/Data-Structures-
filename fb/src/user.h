/*
 * user.h
 *
 *  Created on: 05-Mar-2020
 *      Author: f9
 */

#ifndef USER_H_
#define USER_H_

#include<iostream>
using namespace std;

struct DOB
{
	int day;
	int month;
	int year;
};

struct friend_node;

struct comment_node
{
	int id;
	int comments;
	friend_node *comment_by;
	comment_node * nextcomment;
};

struct friend_node
{
	int id;
	string name;
	DOB date;
	friend_node *down;
	comment_node *nextlink;
};

class Facebook
{
	friend_node *head;
public:
	Facebook();
	int DFS(const int);
	void birthdayMonth(int);
	int minCommentsBFS();
	void createGraph();
	void displayUsers();
	virtual ~Facebook();
};

#endif /* USER_H_ */
