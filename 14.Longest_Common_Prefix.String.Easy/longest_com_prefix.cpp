/*******************************************************************************
 *      File Name: longest_com_prefix.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/10/03-21:38                                    
 * Modified Time: 2017/10/03-21:38                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return string(""); 
		string com_prefix(strs.back());
		cout<<"com_prefix is: "<<com_prefix<<endl; 
		string null_str("");
		int com_len = com_prefix.length();
		const char* ptr = com_prefix.c_str();
		if (com_len == 0)
			return null_str;
		vector<string>::iterator it;
		for(it = strs.begin(); it != strs.end(); it++)
		{
			cout<<"string:"<<*it<<endl;
			while (com_prefix.compare(0, com_len, *it, 0, com_len) != 0)
			{
				com_len--;
				if (com_len == 0)
					return null_str;
			}
		}

		string final_prefix(com_prefix, 0, com_len);
		cout<<"output is: "<<final_prefix<<endl; 
		return final_prefix;
	}
};

int main()
{
	Solution sol;
	vector<string> test1;
	test1.push_back(string("abc"));
	test1.push_back(string("a"));
	test1.push_back(string("ac"));
	test1.push_back(string("a"));
	test1.push_back(string(""));
	test1.push_back(string("abcc"));
	sol.longestCommonPrefix(test1);

	vector<string> test2;
	test2.push_back(string("abc"));
	test2.push_back(string("ab"));
	sol.longestCommonPrefix(test2);

	vector<string> test3;
	sol.longestCommonPrefix(test3);
}
