/*******************************************************************************
 *      file name: longest_uncommon_subsequence_I.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/21-18:51:23                              
 *  modified time: 2018/08/21-18:51:23                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int findLUSlength(string a, string b) {
		int len_a = a.length();
		int len_b = b.length();
		if (len_a != len_b)
			return (len_a > len_b) ? len_a : len_b;
		if (a.compare(b) == 0)
			return -1;
		return len_a;
    }
	/*
    int findLCSlength(string a, string b) {
		int len_a = a.length();
		int len_b = b.length();
		for (int len = len_a; len > 0; len--)
		{
			for (int i = 0; i + len <= len_a; i++)
			{
				string sub = a.substr(i, len);
				if (b.find(sub))
					return len;
			}
		}
		return 0;
    }
    int findLUSlength(string a, string b) {
		int len_a = a.length();
		int len_b = b.length();
		if (a != b)
			return (len_a > len_b) ? len_a : len_b;
		int lcs_len = findLCSlength(a, b);
		if (lcs_len < len_a)
			return len_a;

    }
	*/
};
int main()
{}
