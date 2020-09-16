/*******************************************************************************
 *      file name: string_without_AAA_or_BBB.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/18-10:33:06                              
 *  modified time: 2019/02/18-10:33:06                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
	  if (B > A) return strWithout3a3b(B, A, b, a);
	  while (A-- > 0) {
		res += a;
		if (A > B) res += a, A--;
		if (B-- > 0) res += b;
	  }
	  return res;
	}
};
int main()
{}
