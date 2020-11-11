#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5+5;
int n,m,u,v;
vector<int> adj[N]; // adjacency list
bool vis[N];		//visited array

void BFS(int u){

	queue<int>q;
	vis[u] = true;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		for(int v : adj[u]){ // to push all neighbours of u
			if(!vis[v]){
				vis[v] = true;
				q.push(v);
			}
		}
		q.pop(); // to traverse level by level 
	}
}

int main(){
	cin>>n>>m; // n = nodes , m = edges n>=1
	// undirected graph
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	BFS(1);

	return 0;
}
