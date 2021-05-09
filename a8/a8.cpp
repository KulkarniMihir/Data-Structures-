#include<bits/stdc++.h>
#define INF 10000

using namespace std;

class graph
{
	int v, e;
	int **weighted_matrix;
	int *min_dist;
	int *visited;
    public:
    	graph();
    	graph(int v, int e);
    	void create_graph(int src);
    	void dijkstras();
    	void displayGraph();
    	void displayMinDist();
};

graph::graph()
{
	e = 0;
	v = 0;
}

graph::graph(int v, int e)
{
	this->v = v;
	this->e = e;
	visited = new int[v];
	min_dist = new int[v];
	
	this->weighted_matrix = new int*[v];
	for(int i=0;i <v; i++)
		weighted_matrix[i] = new int[v];
}

void graph::create_graph(int src)
{
	int s, w, d;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			weighted_matrix[i][j] = 0;
		}
		min_dist[i] = INF;
		visited[i] = 0;
	}
	min_dist[src-1] = 0;

	cout<<"\nGraph created."<<endl;
	
	cout<<"\nEnter the source, destination and weight of the edges(exceot 0) :"<<endl;
	for(int i=0; i<e; i++)
	{
		cout<<"\nEdge "<<i+1<<" :";
		cin>>s>>d>>w;
		
		if(s != d)
		{
			if(weighted_matrix[s-1][d-1] == 0 && weighted_matrix[d-1][s-1] == 0)
			{
				weighted_matrix[s-1][d-1] = w;
				weighted_matrix[d-1][s-1] = w;
				cout<<"\nEdge inserted."<<endl;
			}
			else
				cout<<"\nEdge already exists."<<endl;
		}
		else
			cout<<"\nSource and destination cannot be same."<<endl;
	}
}

void graph::displayGraph()
{
	cout<<"\nThe graph is :"<<endl;
	cout<<"------------------------"<<endl;
	
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
			cout<<setw(5)<<weighted_matrix[i][j];
		cout<<endl;
	}
}

void graph::displayMinDist()
{
	cout<<"\nThe shortest paths for the source are :"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Vertex\tDistance"<<endl;
	cout<<"------------------------"<<endl;
	
	for(int i=0; i<v; i++)
	{
		cout<<i+1<<"\t"<<min_dist[i]<<endl;
	}
}


void graph::dijkstras()
{
	int min, dis = 0;
	
	for(int k=0; k<v-1; k++)
	{
		min = -1;
		for(int i=0; i<v; i++)
		{
			if(!visited[i] && (min == -1 || min_dist[i] < min_dist[min]))
				min = i;
		}
		visited[min] = 1;
		
		for(int j=0; j<v; j++)
		{
			if(weighted_matrix[min][j] != 0 && !visited[j])
			{
				dis = min_dist[min] + weighted_matrix[min][j];
				if(dis < min_dist[j])
					min_dist[j] = dis;
			} 
		}
	}
}

int main()
{
	graph g;
	int choice, e, v, s;
	
	do
	{
		cout<<"\n*****DIJKSTRA'S*****\n1)Input graph\n2)Display graph\n3)Find shortest path\n0)Exit\nEnter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			cout<<"\nEnter the number of vertices :"<<endl;
			cin>>v;
			cout<<"\nEnter the number of edges :"<<endl;
			cin>>e;
			cout<<"\nEnter the source :"<<endl;
			cin>>s;
			g = graph(v,e);
			g.create_graph(s);
			break;
		
		case 2:
			g.displayGraph();
			break;
			
		case 3:
			g.dijkstras();
			g.displayMinDist();
			break;
			
		case 0:
			cout<<"\n***Program Closed***\n";
			break;	
		}
	}while(choice!=0);
}
