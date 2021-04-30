#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cmath> 

#define ll long long 
#define endl '\n'

using namespace std;

const int N = 2e5+5;

//prime factors : some prime numbers when you multiply them you get the number itself
// Every number is the result of multiplication of some primes
// n    :   prime factors 
// 10   :   2 5
// 20   :   2 2 5
// 15   :   3 5
// 100  :   2 2 5 5

// get all prime factors of a number 
vector<ll> factorize(ll n){ // o(n)
  vector<ll > v; // prime factors
  for(ll i =2 ; n>1 ; i++){ // o(n)
    while(n%i==0){
      v.push_back(i);
      n/=i;
    }
  }
  return v;
}

// get all prime factors of a number
vector<ll> factorize2(ll n ){ //o(sqrt(n))
  vector<ll > v; // prime factors
  for(ll i=2; i*i <= n ;i++){
    while(n%i==0){
       v.push_back(i);
      n/=i;
    }
  }
  if(n>1)
    v.push_back(n);
  return v;
}
//--------------------------------------------

// Greatest common divisor for 2 numbers 
// gcd(4,8) is 4 because it is the greatest common divisor of 4,8
// 4 : 1 2 4
// 8 : 1 2 4 8

// how to get gcd 
ll gcd(ll a, ll b){ //o(n)
  ll ans = 0;
  for(ll i=min(a,b) ; i>=1 ; i--){
    if(a%i ==0 && b%i==0){
      ans = i ;
    }
  }
  return ans;
}

// Euclidian algorithm to get gcd 
ll gcdE(ll a, ll b){ //o(log(n))
  if(b==0) return a;
  return gcdE(b , a%b);
}


// Least common multiple 
// it is the first number whitch is divisable by 2 numbers 
// lcm(2,5) is 10 because it is the first number divisable by 2 and 5

// how to get lcm 
ll lcm (ll a , ll b){ // o(a*b);
  ll ans=-1;
  for(ll i = max(a,b) ; ; i++ ){
    if(i%a==0 && i%b==0)
      ans=i;
  }
  return ans;
}

/// rule to get lcm
/// gcd(a,b) * lcm(a,b) = a*b
/// lcm(a,b) = a*b / gcd(a,b)
ll lcm2(ll a , ll b) { // o(log(n))
  return (a*b) /__gcd(a,b);
  // return a / __gcd(a,b) *b ; // it is better to avoid Overflow 
}


// when you want to get a power b you multiply a by itself b times 
// 2^10  = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 

// fuction that get a^b using loop
ll power (ll a , ll b){//o(b)
  ll ans =1;
  for(int i=1; i<=b; i++){
    ans*=a;
  }
  return ans;
}

// the same function using recursion 
ll powerRec (ll a, ll b){//o(b)
  if(b==0) return 1;//base case
  return a * powerRec(a, b-1); 
}

// you know that 2^10 = 2^5 * 2 ^5
// so instead of doing b operations we can do log(b) operations by dividing b /2 every time 

ll fastPower(ll a, ll b){// o(log(b))

  if(b==0)  return 1; // base case

  ll result = fastPower(a,b/2);

  if(b%2==0) // b is even
    return result * result;
  
  return result * result * a;  // 2^5 = 2^2 * 2^2 * 2
}



// given a,b,m find  (a^b) % m
//constraints :  1<= a <=10^9   , 1<= b <=10^18 , 2<= m <= 10^9

ll fastPowerMod(ll a, ll b , ll m){// o(log(b))
  if(b==0)  return 1;
  ll result = fastPowerMod(a,b/2,m)%m;

  if(b%2==0)
    return (result * result)%m;

  return (result * result * (a%m))%m; 
}



int main(){

  //ll n ;
 // cin >> n;

 /* vector<ll > ans = factorize2(n);
  for(ll i=0 ; i<ans.size();i++)
    cout << ans[i]<<" ";*/

  ll a , b ,m;
  cin >> a >> b ;

 // cout << gcd(a,b) << endl;
 /* cout << gcdE(a,b) << endl;
  cout << __gcd(a,b) << endl; //built in function in c++ in Algorithm library O(log(b))
*/
  //cout << lcm(a,b);
  //cout << lcm2(a,b);

  /*cout << power(a,b) << endl;
  cout << powerRec(a,b) << endl;
  cout << fastPower(a,b) << endl;
  cin >> m;
  cout << fastPowerMod(a,b,m);
  */


  return 0;
}
