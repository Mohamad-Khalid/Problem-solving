#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int maxW,n, w[1000],p[1000];
int mem[3000][3000];
int solve (int i, int remW){

	if(i==n)
		return 0;
	if(mem[i][remW]>-1)
		return mem[i][remW];

	int op1 = solve(i+1, remW);

	int op2=0;
	if(remW>=w[i]){
		op2=solve(i+1, remW-w[i])+ p[i];
	}
	return mem[i][remW]= max(op1,op2);
}

int main(){
	memset(mem,-1,sizeof mem);
	cin>>maxW>>n;
	for(int i=0;i<n;i++)
		cin>>w[i]>>p[i];
	cout<<solve(0,maxW);


	return 0 ;
}