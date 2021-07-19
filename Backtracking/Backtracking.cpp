#include <iostream>
#include <vector>
using namespace  std;

// Backtracking is a brute force approach to solve many problems 
// it trys all possible solutions 
// Steps : for each sub problem
//          do 
//          recurse 
//          undo


// There  are common problems  on backtracking

//-----------------------------------------------------------------------------------------

// subset sum problem : can you find subset of elements of array their sum = x

int A[]{1,3,5,5,8,10,6};
vector <int > taken;
void subsetSum (int start , int end , int target){ 
    // O(2^n) for each element in n elemnents you have 2 options
  if(start > end ){
    if(target==0){
      for(int i : taken) cout << i << ' ';
        cout << endl;
    }
    return;
  }

    // for the current element we have 2 options : take or leave
    // taking 
  taken.push_back(A[start]);
  subsetSum(start+1,end,target-A[start]);
  taken.pop_back();
    // leave
  subsetSum(start+1, end, target);
}

//-----------------------------------------------------------------------------------------

// Rat in a maze  :
// givin grid contains . for empty cell , # for death , c for cheese
// print the ways can the rat walk through to reach the cheeze
// Sample input 
/*

5 5
.....
..##.
..#..
...##
...#c

*/
int n,m; // row , colomn
char grid[5][5];
string path;
void ratInMaze(int r , int c){
  if(r==n-1 && c==m-1)
    cout << path << endl;   
    // 2 options : right , down 
    // for each option : do , recurse , undo
    // go right and make sure that the right is valid
  if(c+1 < m && grid[r][c+1] != '#'){
        path.push_back('R'); // do 
        ratInMaze(r, c+1); // recurse
        path.pop_back(); // undo
      }
  if(r+1 < n && grid[r+1][c] != '#'){
    path.push_back('D');
    ratInMaze(r+1,c);
    path.pop_back();
  }
}

//-----------------------------------------------------------------------------------------

// knight moves 
//givin grid of n*m and the initial position and the target position
// show the ways can we move the knght to reach from start to end 
// the knight moves are specific
//int n,m;
int rs,cs,re,ce;
int dr[] = {-2,2 ,1 , -1};
int dc[] = {1 ,1 ,2 , 2 };
string name ="ABCD" ,solution;
void knightMoves(int r , int c){
  if(r==re && c==ce)
    cout << solution << endl ;
// you have 4 options 
  for(int i=0 ; i<4 ;i++){
    // new location of the knight
    int nr = r + dr[i] ;
    int nc = c + dc[i] ;
    if(nr < n && nc < m){
      solution.push_back(name[i]);
      knightMoves(nr, nc);
      solution.pop_back();
    }
  }
}

//-----------------------------------------------------------------------------------------

// N Queeen problem
// given grid of n*n put a queen in every row that satisfies the condition :
// every queen dosn't attack another queen 
// the queen attack another one if both are in the same row , colomn, diagonals

const int N = 20;
// int n 
char gridQ[20][20];
int numberOfSolutions ; // number of valid solutions 

void printSolution(){
  numberOfSolutions++;
  for(int i =0 ;i<n ;i++){
    for(int j=0 ; j<n ;j++)
      cout << gridQ[i][j] ;
    cout << endl;
  }
  cout << endl;
  //cout << "-----------------------\n";
}

bool isValid(int r , int c){
  // we know that there is no queen in the same row or below the queen in the same row
  // so we will check the above colomn and digonals

  for(int i=0 ; i<r ;i++){ // above row
    if(gridQ[i][c]=='Q')
      return false;
  } 
  for(int i = 1; r-i >=0 && c+i <n ; i++){ // above right digonal 
    if(gridQ[r-i][c+i]=='Q')
      return false;
  }

  for(int i = 1; r-i>=0 && c-i >=0 ; i++){// above left digonal
    if(gridQ[r-i][c-i]=='Q')
      return false;
  }
  return true;
}

void solveNQueen(int r){
  if(r==n){
    printSolution();
    numberOfSolutions++;
    //return;
  }

  for(int c =0 ; c<n ; c++){ // for each option 
    // do , recurse , undo
    if(isValid(r,c)){
      gridQ[r][c] = 'Q'; // do
      solveNQueen(r+1); // recurse
      gridQ[r][c] = '.'; // undo
    }
  }
}

//-----------------------------------------------------------------------------------------

int main() {
/*int n = sizeof A / sizeof A[0], x; 
cin >> x;
subsetSum(0,n-1,x);*/

/* cin >> n >> m ;
for(int i =0 ; i<n ;i++)
    for(int j=0 ; j<m ; j++)
        cin >> grid[i][j];
ratInMaze(0,0);*/

  /*cin >> n >> m >> rs >> cs >> re >> ce;
  knightMoves(rs,cs);*/


  //freopen("notes.txt","w",stdout);
  //freopen("input.txt","r",stdin);
  // initial state of the grid : doesn't contain any queen
  for(int i=0 ; i<N ;i++){
    for(int j=0 ;j<N ;j++)
      gridQ[i][j]='.';
  }
  cin >> n ;
  solveNQueen(0);




  return 0;
}
