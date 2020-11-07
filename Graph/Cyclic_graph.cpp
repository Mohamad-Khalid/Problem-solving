#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"  

const int N =1e5 +5;
int n,m,u,v;

vector<int > adj[N];
bool vis[N],isSyclic;

void dfs(int u , int p){
	vis[u] = true;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v,u);
		}else if( v !=p){
			isSyclic =  true;
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	cout<<(isSyclic?"YES":"NO");

	
	
return 0 ;
}

