#include <iostream>

using namespace std ;

const int N=1e5+5;

int cnt[N];

int main () {

	// frequency array 
  // given a group of numbers 
	// count the frequency of every number 

	int n,x;
	cin>>n;
	for(int i=0;i<n ; i++)
		cin>>x,cnt[x]++;

	for (int i=0; i<10;i++)
		cout<<i<<" "<<cnt[i]<<endl;

	// time o(n)
	
	return 0;
}
