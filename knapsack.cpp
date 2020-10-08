#include <iostream>
#include <cstring>

using namespace std;

int maxW,n, w[1000],p[1000];
int mem[3000][3000]; // emmoization 

int solve (int i, int remW){

	if(i==n) // base case 
		return 0;

	if(mem[i][remW]>-1) // check if i copmuted before 
		return mem[i][remW];

	int op1 = solve(i+1, remW);// decision 1 : leave it

	int op2=0;
	if(remW>=w[i]){
		op2=solve(i+1, remW-w[i])+ p[i]; // decision 2 : pick it
	}
	return mem[i][remW]= max(op1,op2); // memoization & return 
}

int main(){
	memset(mem,-1,sizeof mem);

	cin>>maxW>>n;

	for(int i=0;i<n;i++)
		cin>>w[i]>>p[i];

	cout<<solve(0,maxW);// first state


	return 0 ;
}
