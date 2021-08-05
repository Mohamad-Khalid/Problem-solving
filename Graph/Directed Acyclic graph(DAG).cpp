#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define endl "\n"  

const int N =1e5 +5;
int n,m,u,v,t;
short vis[N]; // 0>>not visited , 1>>in progrss , 2>>done
vector<int> adj[N];
bool cyclic;

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(vis[v]==0){
			vis[v]=1;
			dfs(v);
		}
		else if(vis[u]==1){
			cyclic=true;
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	// Check is it directed acyclic graph (DAG)?
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}

	dfs(1); 

	for(int i=1;i<n;i++){ // The graph is disconnected 
		if(vis[i]==0){
			dfs(i);
		}
	}

	cout<<(cyclic?"NOT Directed ACyclic graph\n":"Directed ACyclic graph\n");

return 0 ;
}

