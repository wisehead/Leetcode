/*******************************************************************************
 *      file name: excel_sheet_column_num.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/29-11:11                                    
 *  modified time: 17/11/29-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
		//unordered_map<char, int> counts;
		char c;
		int x = 0;
		long long sum = 0;
		long long base = 1;
		string::reverse_iterator it;
		for (it = s.rbegin(); it != s.rend(); it++)
		{
			c = *it;
			cout<<"char c is:"<<c<<endl;
			x = c - 64;
			cout<<"int x is:"<<x<<endl;
			cout<<"base is:"<<base<<endl;
			sum += x*base;
			cout<<"sum is:"<<sum<<endl;
			base = base*26;
		}
		return sum;
    }
};
int main()
{
	Solution sol;
	sol.titleToNumber(string("ZZ"));
}
