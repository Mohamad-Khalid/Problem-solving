 #include <iostream>
 using namespace std;
#define endl '\n'
int t,k,n;
int A[100];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> k >> n;
    for(int i=0; i<n ;i++)
      cin >> A[i];
    bool ok=0;
    for(int msk =0; msk < (1<<n) ;msk++){
      int sum=0;
      for(int i=0;i<n ;i++){
        if( (msk>>i)&1)
          sum+=A[i];
      }
      if(sum==k){
        ok =1 ;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }


  return 0;
}
