/*******************************************************************************
 *      file name: reverse_string.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/06- 1:01                                    
 *  modified time: 18/01/06- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
		reverse(s.begin(), s.end()); 
		return s;
    }
};
int main()
{
	Solution sol;
	string s="apple";
	string out;
	out = sol.reverseString(s);
	cout<<"reverse string for "<<s<<" is:"<<out<<endl;
}
