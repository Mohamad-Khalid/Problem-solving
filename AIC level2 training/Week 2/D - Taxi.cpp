#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input(n,arr)    for(int i=0;i<n;i++)cin>>arr[i]; // 0 => n
#define pi 3.14159265358979323846
#define endl "\n"
#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;
const ll INF=1e18; 
const int N = 1e5+5 , oo=0x3f3f3f3f , mod=1e9+7;

// Never give up
// Never stop learning
int n,n1,n2,n3,n4,taxi; 

int main(){
  fast
  // Taxi
  cin >> n;
  for(int i=0;i<n;i++){
    int x ; cin >> x;
    x==1 ? n1++ : x==2? n2++ : x==3? n3++ : n4++;
  }

  cerr<<"ns "<< n1 <<" "<<n2 <<" "<<n3 <<" " << n4 <<endl;
  // 3
  taxi += n4 ;

  if(n3 >= n1 ){
    taxi+=n3;
    n1 = 0;
  }
  else{
   taxi+=n3;
    n1 -=n3; 
  }
  // 2
  if(n2%2==0){

    taxi+=n2/2 ;
  }
  else{
    taxi+=n2/2 + 1;
    if(n1==1 || n1==2)
      n1=0;
    else if(n1>2)
      n1-=2;
  }
  // 1
  if(n1%4==0)
    taxi += n1/4;
  else
    taxi += n1/4 +1;

  cout<<taxi;



  return 0;
}
