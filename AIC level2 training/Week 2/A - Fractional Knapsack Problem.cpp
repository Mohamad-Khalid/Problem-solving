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
int n,w ;
pair<int,int> a[N] ;
pair<double , int >price_of_item[N];

bool cmp(pair<double , int > x, pair<double , int > y ){
  return x.f > y.f;
}
int main(){
  fast
  // fractional knapsack 
  // Greedy approach

  cin >> n >> w;
  for(int i=0;i<n;i++)
    cin >> a[i].f >> a[i].s ; // vlue weight
  for(int i=0;i<n;i++){
    price_of_item[i].f = (double)a[i].f / a[i].s ;
    price_of_item[i].s = a[i].s;
  }
  sort(price_of_item,price_of_item+n,cmp);
  double max_value=0;
  for(int i=0;i<n;i++){
    if(price_of_item[i].s <= w){
      max_value += (price_of_item[i].f * price_of_item [i].s);
      w-=price_of_item[i].s;
    }
    else{
      max_value+= (w*price_of_item[i].f);
      break;
    }
  }
  cout << fixed << setprecision(8) << max_value ;

 


  return 0;
}
