/*******************************************************************************
 *      file name: reverse_words_in_a_string_III.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-10:09:02                              
 *  modified time: 2018/08/25-10:09:02                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
		int len = s.length();
		int i = 0;
		int pos = 0;
		pos = s.find(' ', i);
		while (pos != string::npos)
		{
			reverse(s.begin() + i, s.begin() + pos);
			cout<<"s is:"<<s<<endl;
			i = pos + 1;
			pos = s.find(' ', i);
		}
		reverse(s.begin() + i, s.end());
		cout<<"s is:"<<s<<endl;
		return s;
    }
};
int main()
{
	Solution sol;
	string input = "Let's take LeetCode contest";
	string res;
	res = sol.reverseWords(input);
}
