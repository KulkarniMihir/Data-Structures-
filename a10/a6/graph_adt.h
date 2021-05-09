//============================================================================
//   Class              : SE  
//   Batch              : F9 
//   Roll No.           : 23133 
//   Filename           : graph_adt.h
//============================================================================

/*
 * graph_adt.h
 *
 *  
 *      Author: e9
 */
 
#ifndef GRAPH_ADT_H_
#define GRAPH_ADT_H_

#include <iostream>
using namespace std;

struct user;
//structure for friend node
struct friends
{
	char fname[30];
	user* U;
	int comments;
	friends* next;
};//end of structure

//structure for date of birth
struct DOB
{
	int date;
	int month;
	int year;
};//end of structure


struct user //structure for user node
{
	char uname[30];
	DOB dob;
	int id;
	user *Dlink;
	friends *next;
};



class Graph //class graph
{
	//data members
	user *head;
	int vertex;
public:
	//public methods
	Graph();
	void user_details();
    void create_graph();
    void add_friend(user*,char*);
    void display_link();
    void add_user();
    void add1_friend();
    void DFS();
    void BFS();
    void maxFriends();
    int findUser(char uname[]);
    void maxComments();
    void birthday_same_month();
	virtual ~Graph();
};//end of class

#endif /* GRAPH_ADT_H_ */

