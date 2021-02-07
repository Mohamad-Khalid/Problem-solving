#include <iostream>
#include <vector>
#include <cstring>
#define f first
#define s second

using namespace std;

const int N = 1e4+5;

int n,m,u,v;
vector<int> adj[N];
bool vis[N];
int ans;
void dfs(int u , int depth){
  for(int v:adj[u])
    dfs(v,depth+1);
  ans=max(ans,depth);
}

int main(){
 int n;
 cin >> n;
 for(int i=1;i<=n;i++){
  u = i;
  cin >> v;
  adj[u].push_back(v);
 }
 for(int i=1;i<=n;i++)
  dfs(i,0);
 cout << ans;

	return 0;
} 
