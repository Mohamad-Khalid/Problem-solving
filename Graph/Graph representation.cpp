#include <iostream>
#include <vector>
using namespace std;

const int N = 100;

int node,edge,u,v;

vector < pair <int,int> > Edgelist; // edge list
bool matrix[N][N];				   // adjacency matrix
vector<int> adj[N];				  // adjacency list

int main(){

	cin>>node>>edge;
	// undirected graph

	for(int i=0;i<edge;i++){  
		cin>>u>>v;
		Edgelist.push_back({u,v});
		Edgelist.push_back({v,u});
	}

	/*for(int i=0;i<edge;i++){
		cin>>u>>v;
		matrix[u][v]=1;
		matrix[v][u]=1;
	}
*/
	/*for(int i=0;i<edge;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u); 
	}
*/
	

	return 0;
}
