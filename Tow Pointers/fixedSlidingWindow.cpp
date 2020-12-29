#include <iostream>

using namespace std ;

const int N = 100 ;
int A[N] , n , k;

int maxSum(){

	int sum=0 , maxV=0;

	for(int i=0;i<k;i++){ // sum of first k element
		sum+=A[i]; 
	}

	int start = 0 , end = start + k - 1; 
	while(end < n){
		maxV= max(sum,maxV);//maximize the sum

		sum-=A[start]; //ignore the first element
		sum+=A[end+1]; // add the one after the last element 

		start++; 
		end++;
	}

	return maxV;
}

int main(){

	cin>> n >> k;
	for(int i=0;i<n;i++)
		cin>>A[i];

	cout<< maxSum();



	return 0;
}
