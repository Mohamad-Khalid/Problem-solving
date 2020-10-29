#include <iostream>
#include <vector>
using namespace std;

const int N = 100;

int n,targetSum,A[N];
vector<int>path;

// print one possible solution
void printSolution(){
    for(int i:path)
        cout<<i<<" ";
    cout<<endl;
}

// find all numbers whose sum is targetSum
void solveSubsetSum(int i, int sum){
    if(i==n || sum==targetSum){
        if(sum == targetSum){
            printSolution();
        }
        return ;
    }

    // option 1 .. pick
    path.push_back(A[i]);
    solveSubsetSum(i+1,sum+A[i]);
    path.pop_back();
    //optin 2 ... leave
    solveSubsetSum(i+1,sum);

}
int main(){

    cin>> n >> targetSum;
    for(int i=0 ; i<n;i++)
        cin>>A[i];

    solveSubsetSum(0,0);

    return 0;
}
