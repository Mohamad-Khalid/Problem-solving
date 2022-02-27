#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
  
typedef long long ll;
typedef unsigned long long ull;

bool f(int x){
  return x>=4;
}

int n,cnt;

int main(){

  cin >> n;
  char grid[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> grid[i][j];
  bool ok=0;
    for(int i=0;i<n;i++){
    for(int j=0 ;j<n ;j++){
      // horizontal
      if(j+5<n){
        cnt=0;
        for(int k=0;k<6;k++){
          if(grid[i][j+k]=='#')
            ++cnt;
        }
        if(f(cnt)) ok=1;
      }

      // vertical 
      if(i+5 <n ){
        cnt=0;
        for(int k=0;k<6 ;k++)
          if(grid[i+k][j]=='#') ++cnt;
        if(f(cnt)) ok=1;
      }

      // diagonal
      if(i+5 < n && j+5<n){
        cnt=0;
        for(int k=0; k<6 ;k++)
          if(grid[i+k][j+k]=='#')++cnt;
        if(f(cnt)) ok=1;
      }

      if((i+5 < n) && (j-5>=0)){
        cnt=0;
        for(int k=0;k<6 ;k++)
          if(grid[i+k][j-k] == '#')++cnt;
        if(f(cnt)) ok=1;
      }


    }
  }
  if(ok) cout << "Yes";
  else cout << "No";
  


return 0;
}
