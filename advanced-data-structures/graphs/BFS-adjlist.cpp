#include <bits/stdc++.h>
using namespace std;
#define nl cout<<"\n";
#define WHITE 0
#define GRAY 1
#define BLACK 2
int *color, *dist, *start, *finish;
map<int, vector<int> > adjlist;
void BFS(int src)
{
	vector<int> neighbours = adjlist[src];
	cout<<"exploring neighbors of "<<src; nl
	queue<int> q;
	for( int i : neighbours)
	{
		if(color[i] == WHITE)
		{
			color[i]=GRAY;
			cout<<"greying node "<<i; nl
			q.push(i);
		}
	}
	while(!q.empty())
	{
		BFS(q.front());
		q.pop();		
	}
	cout<<"blacking. completely visited "<<src; nl
	color[src]= BLACK;
}
int main()
{
	cout<<"Enter the number of nodes in the graph"; nl
	size_t n=0;
	cin>>n;
	color =  new int[n];
	dist = new int[n];
	finish = new int[n];
	start = new int[n];
	memset(color, WHITE,n*sizeof(int));
	memset(dist, 0,n*sizeof(int));
	memset(finish, 0,n*sizeof(int));
	memset(start, 0, n*sizeof(int));
	size_t e=0;
	cout<<"Enter the number of edges in the graph"; nl
	cin>>e;
	cout<<"Enter the edges of the graph (u --> v) pairs"; nl
	size_t u,v;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		adjlist[u].push_back(v);
	}
	for(int i=0;i<n;i++)
	{
		if(color[i]==WHITE)
		{
			cout<<"greying node "<<i; nl
			color[i]=GRAY;
			BFS(i);
		}
	}	
	return 0;
}
