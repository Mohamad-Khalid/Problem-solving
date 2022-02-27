#include <bits/stdc++.h>
using namespace std;

#define	endl '\n'
	
typedef long long ll;
typedef unsigned long long ull;


int main(){
	//Abstract idea : given array of numbers and q queries answer the query about the number 
	// and it should be asked once 
	// It is search problem 
	// we can't use frequency array as the 1<= Ai <=1^9 
	// if N was large then this solution wil fit in the time 


  int n,m,x;
  cin >> n >> m;
  map<int,int> mp;
  for(int i=0;i<n;i++){// n log(n)
  	cin >> x; mp[x]++;
  }
  bool ok=1;
  for(int i=0 ; i<m; i++){ //m log(N)
  	cin >> x;
  	if(mp[x]>0) mp[x]--;
  	else ok=0;
  }
  cout << (ok? "Yes" : "No");

	
return 0;
}
