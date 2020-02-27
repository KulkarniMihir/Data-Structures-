/*
 * graph.h
 *
 *  Created on: 24-Feb-2020
 *      Author: f9
 */

#ifndef GRAPH_H_
#define GRAPH_H_

struct dob {
	int date;
	int month;
	int year;
};

class friend_node;

class relations {
public:
	relations();
	int comments;
	relations *nxt;
	friend_node *comment_by;
};


class friend_node {

public:
	friend_node();
	int id;
	struct dob d;
	friend_node *down;
	relations *next;
};

class graph {
	int v,e;
	friend_node *head;
public:
	graph();
	virtual ~graph();
	void insert();
	void display();
	friend class friend_node;
	friend class relations;
};


#endif /* GRAPH_H_ */
