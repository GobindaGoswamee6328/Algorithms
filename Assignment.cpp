
#include <iostream>
#include <limits.h>
#include<stdbool.h>
#define V 5
using namespace std;

int minKey(int key[], bool mstSet[])
{

int min = INT_MAX;
int min_index;

for (int v = 0; v < V; v++)
if (mstSet[v] == false && key[v] < min)
min = key[v], min_index = v;

return min_index;
}


int printMinimumSpanningTree(int T[], int n, int G[V][V])
{

int Temp[V][V];
for (int i = 0; i < V; i++){
for (int j = 0; j < V; j++) {
Temp[i][j] = 0;
}
}

for (int i = 1; i < V; i++) {
Temp[T[i]][i] = G[i][T[i]];
Temp[i][T[i]] = G[i][T[i]];
}

cout<<"\n\nMininum Spanning Tree is :\n";
for (int i = 0; i < V; i++){
for (int j = 0; j < V; j++) {
cout<<Temp[i][j]<<" ";
}
cout<<"\n";
}
}


void primMinimumSpanningTree(int G[V][V])
{
// Array to store constructed Minimum Spanning Tree
int T[V];

int key[V];
bool mstSet[V];

// Initialize all keys as INFINITE
for (int i = 0; i < V; i++){
key[i] = INT_MAX;
mstSet[i] = false;
}
// Always include first 1st vertex in MST.
key[0] = 0;
T[0] = -1; // First node is always root of MST

// The MST will have V vertices
for (int k = 0; k < V-1; k++)
{
// Pick the minimum key vertex from the set of vertices not yet included in MST
int u = minKey(key, mstSet);

// Add the picked vertex to the MST Set
mstSet[u] = true;
for (int v = 0; v < V; v++)
if (G[u][v] && mstSet[v] == false && G[u][v] < key[v])
T[v] = u, key[v] = G[u][v];
}

printMinimumSpanningTree(T, V, G);
}


int main()
{

cout<<"Enter adjacency matrix for "<<V<<" Rows and "<<V<<" Columns\n";
int G[V][V];
for (int i = 0; i < V; i++){
for (int j = 0; j < V; j++) {
cin>>G[i][j];
}
}

cout<<"\n\nOriginal Tree is :\n";
for (int i = 0; i < V; i++){
for (int j = 0; j < V; j++) {
cout<<G[i][j]<<" ";
}
cout<<"\n";
}

primMinimumSpanningTree(G);
return 0;
}

