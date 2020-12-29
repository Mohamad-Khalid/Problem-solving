#include <iostream>

using namespace std ;

const int N = 100 ;
int A[N] , n , wanted;


int solve (){
	int p1=0,p2=0,sum=0,ans=0;
	while(p2<n){

		while(sum + A[p2] >= wanted){
			sum+=A[p2];
			p2++;
		}
		ans = max(ans,sum);
		sum-=A[p1];
		p1++;

	}
	return ans;

}

int main(){
	// given array , find the maximum sum of subarray which sum doesn't exceed wanted
	cin>> n >> wanted;
	for(int i=0;i<n;i++)
		cin>>A[i];

	cout<<solve();



	return 0;
}
