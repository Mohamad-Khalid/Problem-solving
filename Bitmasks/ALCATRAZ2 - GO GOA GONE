 #include <iostream>
 using namespace std;
#define endl '\n'

int n=8,p,A[10];
pair<int,int> problems[70];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<n;i++)
    cin >> A[i];

  cin >> p;
  for(int i=0; i<p ; i++ ){
    cin >> problems[i].first >> problems[i].second;
    --problems[i].first;
    --problems[i].second;
  }

  int ans=-1;

  for(int i=0;i<(1<<n);i++){

    bool valid = true;
    for(int u=0;u<p; u++){
      if( ((i >> problems[u].first) &1) && ((i >> problems[u].second) &1) ){
        valid =0;
        break;
      }
    }

    if(!valid)
      continue ;

    int sum=0;
    for(int j=0; j<n; j++){
      if((i>>j)&1){
        sum+=A[j];
        //cout << "a[i] "<< A[i] << endl;
      }
    }
    //cout << sum << endl;
    ans=max(ans, sum);
  }

  cout << ans ;

  return 0;
}
