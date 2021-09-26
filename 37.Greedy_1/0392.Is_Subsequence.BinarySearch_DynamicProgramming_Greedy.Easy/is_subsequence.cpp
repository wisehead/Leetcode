/*******************************************************************************
 *      file name: is_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/11-16:48:02                              
 *  modified time: 2020/09/11-16:48:02                              
 *******************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
		int last_pos = 0;
		const char *buf = s.c_str();
		for (int i = 0; i < s.length(); i++)
		{
			int pos = t.find(buf[i], last_pos);
			if (pos == string::npos) return false;
			last_pos = pos+1;
		}
		return true;
    }
};

int main()
{}
