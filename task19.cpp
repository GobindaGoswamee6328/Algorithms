
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int>* graph,int u,int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}
int main()
{
	int n;
	int e;
	int v,u;
	cout<<"Enter the Size of Vertices"<<endl;
	cin>>n;
	cout<<"Enter the Size of Edges"<<endl;
	cin>>e;
	int copy;
	copy=n;
	int a[n+1]={0};
	vector<int> graph[n+1];
	for(int i=1;i<=e;i++)
	{
		cout<<"From ";
		cin>>u;
		cout<<"To ";
		cin>>v;
		addEdge(graph,u,v);
	}
	vector<int>::iterator it;
	queue<int> q;
	q.push(1);
	int x;
	cout<<"BFS is"<<endl;
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		cout<<x<<" ";
		for(it=graph[x].begin();it!=graph[x].end();it++)
		{
			if(a[*it]!=1)
			{
				q.push(*it);
				a[*it]=1;
			}
		}
	}
	return 0;
}
