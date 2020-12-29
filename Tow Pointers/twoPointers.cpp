#include <iostream>

using namespace std ;

int main(){

	int a [] = {2,3,5,7,8,9}; // sorted array
	int wanted = 20 ;	//two numbers with sum = 10

	// we can solve this in o(n^2) by nested loop
	// or o(nlog(n)) by binary search 
	// or o(n) by two pointers technique

	// two pointers approach
	int start = 0 , end = 5;
	bool ok = false ;
	while(start < end){

		int x = a[start] + a[end] ;
		if(x > wanted )
			end--;
		else if(x < wanted)
			start++;
		else{
			ok = true;
			cout<< start << " " << end ;
			break;
		}
	}
	if(ok == false)
		cout<< "NOT FOUND\n";

	return 0;
}
