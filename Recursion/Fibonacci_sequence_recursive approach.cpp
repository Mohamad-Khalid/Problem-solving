
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl "\n"  

// return fibonaccie of x
long long fib(int x){ //  o(2^n)
	if(x==1 || x==2 )
		return 1;
	return fib(x-1)+fib(x-2);
} 

const int N =1e5 +5;
long long mem[N];
// return fibonaccie of x by using dynamic programming technique
long long fib_dp(int x){ // o(n)
	if(x==1 || x==2)
		return 1;
	if(mem[x]!=-1)
		return mem[x];

	return mem[x]= fib_dp(x-1)+fib_dp(x-2);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(mem,-1,sizeof mem);

	int x;
	cin>>x;
	cout<<fib_dp(x)<<endl;
	cout<<fib(x)<<endl;	


	
return 0 ;
}

