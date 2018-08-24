/*******************************************************************************
 *      file name: reverse_II.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/24-06:29:39                              
 *  modified time: 2018/08/24-06:29:39                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
		int len = s.length();
		for (int i=0; i<len; i += 2*k)
		{
			if (i + k < len)
			{
				reverse(s.begin() + i, s.begin() + i + k);
				cout<<"s is:"<<s<<endl;
			}
			else
			{
				reverse(s.begin() + i, s.end());
				cout<<"s is:"<<s<<endl;
			}
		}
		return s;
    }
};
int main()
{
	Solution sol;
	string str = "abcdefg";
	int k = 2;
	string res;
	res = sol.reverseStr(str, k);
}
