#include <iostream>

using namespace std ;

const int N=1e5+5;

int sum[N],a[N];

int main () {

	// prefix sum 
	// Classical problem 
	// given an array and q queries , each query you are given l,r
	// print the sum of elements from l to r inclusive 
	// n >= 1e5 , q<=1e5

	// first approach (brute force ) o(n*q)
	// second approach (prefix sum ) o(q)
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];

	sum[0]=a[0];
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i]; // prefix array 

	while (q--){
		int l,r; cin>>l>>r;

		if(l!=0) //there is no index = -1
			cout<<"sum "<<sum[r]-sum[l-1]<<endl;
		else
			cout<<"sum "<<sum[r]<<endl;
	}



	return 0;
}
