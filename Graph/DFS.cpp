#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;

int n,m,u,v; // n-> nodes, m->edges , u,v -> adjacent nodes
vector<int> adj[N]; // adjecency list

bool vis[N]; // visted array-initialy all elements = false

void DFS(int u){
	vis[u]= true;  		   // mark this node as visited
	for(int v : adj[u]){  // traverse all neighbours
		if(!vis[v]){     // for each non visited node 
			DFS(v);	    //  make DFS again from this node
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DFS(1); 
	

	return 0;
}