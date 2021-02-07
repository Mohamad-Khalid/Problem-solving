#include <iostream>
#include <vector>
#include <cstring>
#define f first
#define s second

using namespace std;

const int N = 1e4+5;

int n,m,u,v;
vector<int> adj[N];
int c[N]; //0 not colrerd , 1 red , 2 black
bool biPartite = true;

void dfs(int u , int color){
  c[u]=color;
  for(int v : adj[u]){
    int newColor = (color==1?2:1);
    if(!c[v])
      dfs(v,newColor);
    else if(c[u]==c[v]){
   /*   cerr << "c "<<c[u]<<" "<<c[v]<<endl;
      cerr <<"u,v "<< u <<" "<<v<<endl;*/
      biPartite = false;
    }
  }
}

void init(){
  memset(c,0,sizeof c);
  for(int i=0;i<N;i++)
    adj[i].clear();
  biPartite = true;
}

int main(){
  
  int t;
  cin >> t;
  for(int tc=1 ; tc<=t ;tc++){
    cin >> n >> m;
    init();
    for(int j=0;j<m;j++){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
      if(!c[i])
        dfs(i,1);
    }
    cout << "Scenario #"<<tc<<":\n";
    cout << (biPartite==1? "No suspicious bugs found!" :"Suspicious bugs found!" ) << endl;
  }

  
	return 0;
} 
