#include <iostream>
using namespace std;


int main(){

 /* Bitwis Operations  & | ^ ~ << >> 

   and &  --> do and operation to the bits of two numbers 
   
   5 & 4 = 4 
   decimal   binary   result
   5         101    
   4         100  
   _______________
             100      4 
 */

 /*

  Note #1 : The first bit of any odd number is 1 and even number is 0
            so we can know the number is even or odd by doing bitwise and with 1 
            if the result is 1 --> the number is odd 
            if the result is 0 --> the number is even

 */ 
  int x=5; cin >> x;
  cout << (x&1) << endl; 

  // Note #2 : Mask is a number 
  // Note #3 : In C++ --> 0b100  is binary of the number 
   int bNumber = 0b100; cout << bNumber << endl;

   /*
    Bitwus Or | --> do bitwis or for two numbers 
    
  binary :   6  |  1  =  8 
  decimal:  110 | 001 = 111 
  
   */

    // Note #4 : if you want to turn on a bit do or with 1 
   //            if you want to turn off a bit do and with 0

   /*
      Bitwise not ~ --> filip the bits of the number 

      ~00010 --> 11101  
   */
   cout << ~x << endl ;
   // Note #5 : bitwis not to a number = -number-1

   // shift left << : shift the bits to the lift and put 0 in the rightmost
   // shift right >> : shift the bits to the right and put 0 in the leftmost
   // <<  = number * 2 
   // >>  = number / 2 

   cout << (x >> 1 ) << " "<< ( x << 1 ) << endl;

  // Note #6 : to pritnt the binary of a number ( x >> i )&1 
   // print the bits from left to right as we write it on paper 
  for(int i=31 ; i>=0 ; --i)
    cout << ((x>>i) &1);
  cout << endl;

  // Note #7 : to On the Kth bit of x 
  int k ; cin >> k;
  cout << (x | (1<<k)) << endl;
  // Note #8 : to Off the Kth bit of x
  cout << (x & ~(1<<k) ) << endl;

  // XOR  ^ exclusive or  1^1 = 0 
  // flip the bit  [ b^1 = !b ]
  cout << (x ^ 1) << endl;
  //Toggle the Kth bit
  cout << ( x ^(1<<k)) << endl;

  cout << "__________________\n";
  int res=0;
  for(int i=1 ; i<20 ; i++ )
    res^=i,cout << res << endl;

  // Note #9 : xor sum from 1 to n --> search for pattern
  // Note #10 : xor sum for number appears even time is 0


  
  return 0;
}
