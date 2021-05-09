//============================================================================
//   Class              : SE  
//   Batch              : F9 
//   Roll No.           : 23133
//   Filename           : graph_imp.cpp
//============================================================================

#include<iostream>
#include<string.h>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
#include "graph_adt.h"

Graph::Graph() {
	// TODO Auto-generated constructor stub
	head=NULL;
	vertex=0;
}//end of constructor

//get user information
void Graph::user_details()	// function to take input of user details
{
	cout<<"\nEnter no of users  :  ";
	cin>>vertex;
	int i;

	user *temp;
	for(i=1;i<=vertex;i++)
	{
		if(i==1)
		{
			//create 1st node
			head=new user();
			temp=head;
		}
		else
		{
			temp->Dlink=new user();
			temp=temp->Dlink;
		}
		//get details
		cout<<"\nEnter detail of "<<i<<"th user\n";
		cout<<"\nEnter name  :  ";
		cin>>temp->uname;
		cout<<"\nEnter DOB  (dd/mm/yy) :  ";
		cin>>temp->dob.date;
		cin>>temp->dob.month;
		cin>>temp->dob.year;
		temp->Dlink=NULL;
		temp->id=i-1;

	}
}//end of function


void display_list(user* temp,user* head)	// shows list of users
{
	int i=1;
	while(head!=NULL)//list is not empty
	{
		if(head!=temp)//list contains more than one nodes
		{
			cout<<"\n"<<i<<"] "<<head->uname;
			i++;
		}
		head=head->Dlink;
	}
	cout<<"\n\n";
}//end of function

void Graph::create_graph()	// function to create graph
{
	user* temp=head,*p;
	char name[50];
	int i,n,j;
	for(i=1;i<=vertex;i++)
	{
		cout<<"\nEnter no of friends of "<<temp->uname<<"  :  ";
		cin>>n;
		if(n!=0)
		{
			cout<<"\nEnter Name of friends from following list  :\n   ";
			display_list(temp,head);
			for(j=1;j<=n;j++)
			{
				cout<<"\n "<<j<<")";
				cin>>name;
				//add name to list of friends of temp
				add_friend(temp,name);
				p=head;
				while(p!=NULL)
				{
					if(strcmp(p->uname,name)==0)	// friend with same name does not exist then add the friend
					{
						//also add temp in friends list of name
						add_friend(p,temp->uname);
						break;
					}
					p=p->Dlink;
				}

			}
		}
		temp=temp->Dlink;
	}
}//end of function


void Graph::add_friend(user* P,char* name)
{
	friends* temp=P->next;
	user* u=head;
	//check whether name is present in list
	//and if present find address of that user node
	while(u!=NULL)
	{
		if(strcmp(u->uname,name)==0)
			break;
		u=u->Dlink;
	}
	if(u==NULL)
	{
		cout<<"\nUser not found\n";
		return;
	}

	//if it is first friend
	if(temp==NULL)
	{
		P->next=new friends();
		strcpy(P->next->fname,name);
		P->next->U=u;
		P->next->next=NULL;
		cout<<"\nEnter no of comments  by "<<name<<" to "<<P->uname<<" :   ";
		cin>>P->next->comments;
	}
	else
	{
		//add to last in friendlist
		while(temp->next!=NULL)
		{
		    if(strcmp(name,temp->fname)==0)
		    	return;
			temp=temp->next;
		}
		if(strcmp(name,temp->fname)==0)
			    return;
		temp->next=new friends();
		temp->next->next=NULL;
	    strcpy(temp->next->fname,name);
	    temp->next->U=u;
	    cout<<"\nEnter no of comments  by "<<name<<" to "<<P->uname<<" :   ";
	    cin>>temp->next->comments;
	}

}//end of function



void Graph::display_link()// function to display friends with links
{
	user* temp=head;
		friends *f=temp->next;
		cout<<"------------------------------------------------------------------------------------------------------\n\n";

		while(temp!=NULL)
		{
			cout<<"|"<<setw(2)<<temp->id<<"|"<<setw(10)<<temp->uname<<"|"<<setw(2)<<temp->dob.date<<"/"<<setw(2)<<temp->dob.month<<"/"<<setw(2)<<temp->dob.year<<"|"<<"   ";
			f=temp->next;
			while(f!=NULL)
			{
				cout<<" -->  ";
				cout<<"|"<<setw(10)<<f->fname<<"|"<<setw(2)<<f->comments<<"|   ";
				f=f->next;
			}

            cout<<"\n";
			temp=temp->Dlink;
		}

		cout<<"-----------------------------------------------------------------------------------------------------\n\n";

}//end of function


void Graph::add_user()//function to add new user
{
	user* temp=head;
	int i=0;
	//insert at end in user list
	while(temp->Dlink!=NULL)
	{
		i++;
		temp=temp->Dlink;
	}
	temp->Dlink=new user();
	temp=temp->Dlink;
	i++;
	cout<<"\nEnter name  :  ";
	cin>>temp->uname;
	cout<<"\nEnter DOB   :  ";
	cin>>temp->dob.date>>temp->dob.month>>temp->dob.year;
	temp->Dlink=NULL;
	temp->id=i;
	vertex++;

}//end of function


void Graph::add1_friend()	// add
{
	user* temp=head;
	char name[30],fnm[30];
	cout<<"\nWhose friend ? ";
	cin>>name;
	cout<<"\nEnter name from following list  :  \n";
	display_list(NULL,head);
	cin>>fnm;

	while(temp!=NULL)
	{
		if(strcmp(temp->uname,name)==0)
			add_friend(temp,fnm);
		else if(strcmp(temp->uname,fnm)==0)
			add_friend(temp,name);
		temp=temp->Dlink;
	}

}//end of function


void Graph::DFS()// function to implement dfs algorithm
{
	stack<user*> st; //stack for DFS
    //array to determine that whether vertex is visited or not
	int visited[20]={0};
	st.push(head);//push head
	visited[head->id]=1;
	user* temp;
	friends* f;
	while(!st.empty())
	{
		//pop and display
		temp=st.top();
		st.pop();
		cout<<temp->uname<<" --> ";
		f=temp->next;
		while(f!=NULL)
		{
			//if not visited , then push
			if(visited[f->U->id]==0)
			{
				visited[f->U->id]=1;
				st.push(f->U);
			}
			f=f->next;
		}
	}
}//end of function


void Graph::BFS()	// function to implement bfs algorithm
{
	queue<user*> st;  //Queue for BFS

	int visited[20]={0};
	st.push(head);
	visited[head->id]=1;
	user* temp;
	friends* f;
	while(!st.empty())
	{
		temp=st.front();
		st.pop();
		cout<<temp->uname<<" --> ";
		f=temp->next;
		while(f!=NULL)
		{
			if(visited[f->U->id]==0)//if not visited push it in stack
			{
				visited[f->U->id]=1;
				st.push(f->U);
			}
			f=f->next;
		}
	}
}//end of function



void Graph::maxFriends()	// function to count maximum friends
{
	//by using DFS
	    stack<user*> st;

		int visited[20]={0},i=0,j;
		int *frnd=new int[vertex];
		for(i=0;i<vertex;i++)
			frnd[i]=0;

		st.push(head);
		visited[head->id]=1;
		user* temp,*t;
		friends* f;
		while(!st.empty())
		{
			temp=st.top();
			st.pop();
			j=temp->id;
			//cout<<temp->uname<<" --> ";
			f=temp->next;
			while(f!=NULL)
			{
				frnd[j]++; //get count of friends for each user in array
				if(visited[f->U->id]==0)
				{
					visited[f->U->id]=1;
					st.push(f->U);

				}
				f=f->next;
			}
		}
		temp=head;
		int max=frnd[0];
		cout<<"\n"<<temp->uname<<" has "<<frnd[0]<<" friends\n";
		t=temp;
		//temp=temp->Dlink;
		//find user with maximum friends
		for(i=1;i<vertex;i++)
		{
			temp=temp->Dlink;
			cout<<"\n"<<temp->uname<<" has "<<frnd[i]<<" friendss\n";
			if(max<frnd[i])
			{
				max=frnd[i];
				t=temp;
			}

		}
		cout<<"\n\nUser who got maximum friends =  "<<t->uname<<"\n";
		    cout<<"Total friends =  "<<max;
}//end of function

int Graph::findUser(char uname[])	//function to return user id
{
	user *temp = head;
	
	while(temp!=NULL)
	{
		if(!strcmp(temp->uname,uname))	//if name matches to user name return id
			return temp->id;
		temp = temp->Dlink;
	}
	return -1;
}

void Graph::maxComments()
{
	int *comm = new int[vertex];
	
	for(int i=0;i<vertex;i++)
		comm[i]=0;
		
	user *t1,*t2,*temp = head;
	friends *f;
	
	while(temp!=NULL)
	{
		f = temp->next;
		
		while(f!=NULL)
		{
			int loc = findUser(f->fname);
			
			if(loc != -1)
				comm[loc]+=f->comments;		//get the count of comments for each user in array
				
			f = f->next;
		}
		
		temp = temp->Dlink;
	}
	
	temp=head;
	int max,min;
	max=min=comm[0];
	cout<<"\n"<<temp->uname<<" posted "<<comm[0]<<" comments\n";
	t1=t1=temp;
	//temp=temp->Dlink;
	//find user with maximum friends
	for(int i=1;i<vertex;i++)
	{
		temp=temp->Dlink;
		cout<<"\n"<<temp->uname<<" posted "<<comm[i]<<" comments\n";
		if(max<comm[i])
		{
			max=comm[i];
			t1=temp;
		}
		if(min>comm[i])
		{
			min=comm[i];
			t2=temp;
		}

	}
	cout<<"\n\nUser who posted maximum comments =  "<<t1->uname<<"\n";
	cout<<"Total friends =  "<<max;
	cout<<"\n\nUser who posted minimum comments =  "<<t2->uname<<"\n";
	cout<<"Total friends =  "<<min;
}

void Graph::birthday_same_month()	// function to users with the same birthday month
{
	int m,i=1;
	cout<<"\nEnter month  :  ";
	cin>>m;
	user* temp=head;
	while(temp!=NULL)
	{
		//if month matches,then display user name
		if(temp->dob.month==m)
		{
			cout<<"\n"<<i<<"] "<<temp->uname;
			i++;
		}
		temp=temp->Dlink;
	}
}//end of function


Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
