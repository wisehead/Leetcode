/*******************************************************************************
 *      file name: additive_number.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/28-14:12:19                              
 *  modified time: 2020/10/28-14:12:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;
/*
use a helper function to add two strings.

Choose first two number then recursively check.

Note that the length of first two numbers can't be longer than half of the initial string, so the two loops in the first function will end when i>num.size()/2 and j>(num.size()-i)/2, this will actually save a lot of time.

Update the case of heading 0s
e.g. "100010" should return false
*/
class Solution {
public:
bool isAdditiveNumber(string num) {
  for(int i = 1; i <= num.size()/2; i++) {
   for(int j = 1; j <= (num.size()-i)/2; j++) {
     if (i >= 2 && num[0] == '0' || j >= 2 && num[i] == '0' || i+j >= 4 && num[i+j] == '0') 
         continue;
     if (addNum(stol(num.substr(0,i)), stol(num.substr(i,j)), num.substr(i+j))) 
         return true;
    }
  }
  return false;
}
bool addNum(long num1, long num2, string num){
   if (num.size() > 1 && num[0] == '0') return false;
   
    long sum = num1 + num2;
    long len = 0;
    if (sum != 0 && sum < LONG_MAX)
        len = static_cast<long>(log10(sum)) + 1;
    else len = 1;
   
    if (num.length() > 18 )   {
        if(sum == stol(num.substr(0, len))) return addNum(num2, sum, num.substr(len));
        else return false;
    }
        
    
   long numI = stol(num);    
   if (numI == sum) return true;
   if (numI < sum || sum != stol(num.substr(0, len))) return false;\  
   else return addNum(num2, sum, num.substr(len));
}
};
int main()
{}
