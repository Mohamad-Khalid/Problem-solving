#include <iostream>
#include <algorithm>
using namespace std;

// This is for positive numbers only

string addTwoNumbers(string num1 , string num2) {

  if(num1.size()==0) return num2;
  if(num2.size()==0) return num1;

  reverse(num1.begin(),num1.end());
  reverse(num2.begin(),num2.end());
  string ans = "";
  if(num1.size() > num2.size()) swap(num1,num2);
  // num1 is smaller in size
  int carry =0 , temp=0;
  for(int i=0 ;i<num1.size();i++){
    temp=0;
    temp+= (num1[i]-'0') + (num2[i]-'0');
    temp += carry;
    carry=0;
    int dg = temp%10;
    ans+= char(dg+'0');
    carry = temp/10;
  }

  for(int i= num1.size() ;i<num2.size();i++){
    temp=0;
    temp+= (num2[i]-'0');
    temp += carry;
    carry=0;
    int dg = temp%10;
    ans+= char(dg+'0');
    carry = temp/10;
  }
  if(carry) ans+= char(carry+'0');

  reverse(ans.begin(),ans.end());
  return ans;
}

string multiplyTwoNumbers(string num1, string num2) {
  if(num1=="0" || num2=="0") return "0";
  reverse(num1.begin(),num1.end());
  reverse(num2.begin(),num2.end());
  if(num1.size() > num2.size() ) swap(num1,num2);

  vector<string> values;
  for(int i=0 ;i<num2.size();i++){
    string ans ="";
    int carry=0,temp=0;

    for(int j=0;j<num1.size();j++){
      temp=0;
      temp = (num2[i]-'0') * (num1[j]-'0');
      temp+=carry;
      carry =0;
      ans+= char((temp%10) + '0');
      carry = temp/10;
    }
    if(carry) ans += char(carry+'0');
    reverse(ans.begin(),ans.end());
    for(int k =0 ; k<i ;k++)
      ans+='0';
    values.push_back(ans);
  }

  string result ="";
  for(auto number : values)
    result = addTwoNumbers(result,number);

  return result;

}


int main(){

  string number1,number2;
  cin >> number1 >> number2;
  cout << "sum = " << addTwoNumbers(number1,number2) << '\n';
  cout << "multiply = " <<multiplyTwoNumbers(number1,number2) << '\n';


return 0;
}
