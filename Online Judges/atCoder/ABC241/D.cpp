#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
  
typedef long long ll;
typedef unsigned long long ull;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  //  10 20 20 30 *
  ll q,c,x,k;
  cin >> q;
  multiset<ll> st;
  while(q--){
    cin >> c;
    if(c==1){
      cin >> x ;
      st.insert(x);
    }
    if(c==2){
      cin >> x >> k;
      bool ans=1;
      auto val = st.upper_bound(x);
      auto temp = st.begin();
      while(k){
        if(val==temp){
            if(k>0) ans=0;
            //cout <<"k "<<k <<endl;
          break;
        }
        --val;
        --k;
      }

      if(ans) cout << *val<<endl;
      else cout << -1 << endl;      
    }
    if(c==3){
      cin >> x >> k;
      bool ans=1;
      auto val = st.lower_bound(x);
      if(val!=st.end()){
        --k;
        while(k--){
          ++val;
          if(val==st.end())
            ans=0;
        }
      }
      else 
        ans=0;
      if(ans) cout << *val<<endl;
      else cout << -1 << endl;

    }

  } 

return 0;
}
