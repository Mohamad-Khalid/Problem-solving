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

pair<int,int >a[N];
bool cmp(pair<int,int>a , pair<int,int>b){
  if(a.f==b.f)
    return a.s > b.s;
  return a.f < b.f;
}

int main(){
  fast

 //freopen("notes.txt","r",stdin); 
 // Greedy approoch
 ll n,r,avg,sum=0;
 cin >> n>> r>>avg;
  ll essy=0,mark=0;
 for(int i=0;i<n;i++){
  cin>>a[i].f>>a[i].s;
  sum+=a[i].f;
  swap(a[i].f,a[i].s);
 }
 if(sum/n > avg ){
  cout<<0;
 }
 else {
  sort(a,a+n,cmp);

  ll need=(n*avg)-sum;//3

  for(int i=0;i<n && need >0 ; i++){
    if(r-a[i].s  <= need ){
      need -= r-a[i].s ;
      essy+= (r-a[i].s) *(a[i].f);
    }
    else{
      essy += need * a[i].f;
      need=0;  
    }
    
  }
  cout<< essy ;
}

  return 0;
}
