#include<bits/stdc++.h>
using namespace std;

class graph
{
	int v,e;
	int **weighted_matrix;
	int **mst;
	int **visited;
	int *parent;
	int cost;
	
	public:
		graph();
		graph(int v,int e);
		void create_graph();
		void display_graph();
		void display_mst();
		int findParent(int v);
		void kruskals();
		
};

graph::graph()
{
	v=0;
	e=0;
}		

graph::graph(int v, int e)
{
	this->v = v;
	this->e =e;
	cost = 0;
	parent = new int[v];
	
	this->weighted_matrix = new int*[v];
	for(int i=0;i<v;i++)
		weighted_matrix[i] = new int[v];
	
	this->mst = new int*[v];
	for(int i=0;i<v;i++)
		mst[i] = new int[v];
		
	this->visited = new int*[v];
	for(int i=0;i<v;i++)
		visited[i] = new int[v];	
}

void graph::create_graph()
{
	int src,dest,weight;
	
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			weighted_matrix[i][j] = 0;
			visited[i][j] = 0;
		}	
		parent[i] = i;
	}	
	cout<<"\nGraph is initialized";
	
	cout<<"\nEnter source, destination and weight of edge(exept zero) : ";
	for(int i=1;i<=e;i++)
	{
		cout<<"\nEdge 	"<<i<<" :";
		cin>>src>>dest>>weight;
		
		if(src != dest)		//not a self loop
		{
			if(weighted_matrix[src-1][dest-1] == 0 && weighted_matrix[dest-1][src-1] == 0)
			{
				weighted_matrix[src-1][dest-1] = weight;
				weighted_matrix[dest-1][src-1] = weight;
				cout<<"\nEdge inserted";
			}
			else cout<<"\nEdge already exists";
		}
		else
			cout<<"\nSource and destination same ! Self-loop exits ";
	}
					
}
		
void graph::display_graph()
{
	cout<<"\nThe graph is :"<<endl;
	cout<<"------------------------"<<endl;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
			cout<<"\t"<<weighted_matrix[i][j];
		cout<<"\n";
	}
}


void graph::display_mst()
{
	cout<<"\nThe minimum spanning tree is :"<<endl;
	cout<<"------------------------"<<endl;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
			cout<<"\t"<<mst[i][j];
		cout<<"\n";
	}
	cout<<"\nThe cost of the MST is : "<<cost<<endl;
}

int graph::findParent(int v)
{
	if(parent[v] == v)
		return v;
	return findParent(parent[v]);
}

void graph::kruskals()
{
	int min_weight,min_src,min_des;
	int k = 1;
	
	while( k!=v )
	{
		min_weight = 99;
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(weighted_matrix[i][j] != 0 && !visited[i][j] && weighted_matrix[i][j] <= min_weight)
				{
					min_weight = weighted_matrix[i][j];
					min_src = i;
					min_des = j;
				}	
			}	
		}
		
		if(findParent(min_src) != findParent(min_des))
		{
			mst[min_src][min_des] = min_weight;
			mst[min_des][min_src] = min_weight;
			parent[min_des] = min_src;
			cost += mst[min_src][min_des];
			visited[min_src][min_des] = 1;
			visited[min_des][min_src] = 1;
			k++;
		}
	}
}

int main()
{
	graph g;
	int choice, e, v;
	
	do
	{
		cout<<"\n---Kruskal's Algorithm---\n1)Input graph\n2)Display graph\n3)Find minimum spanning tree\n0)Exit\nEnter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the number of vertices :"<<endl;
			cin>>v;
			cout<<"\nEnter the number of edges :"<<endl;
			cin>>e;
			g = graph(v,e);
			g.create_graph();
			break;
		
		case 2:
			g.display_graph();
			break;
			
		case 3:
			g.kruskals();
			g.display_mst();
			break;
			
		case 0:
			cout<<"\n***Program closed***\n";
			break;
		}
	}while(choice!=0);
}		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
















			










