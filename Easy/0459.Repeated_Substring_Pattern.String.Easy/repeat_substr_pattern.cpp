/*******************************************************************************
 *      file name: repeat_substr_pattern.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/19-11:36:34                              
 *  modified time: 2018/07/19-11:36:34                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	bool checkRepeat(string s, string p)
	{
		int slen = s.length();
		int plen = p.length();
		if (slen % plen != 0 || slen == plen)
			return false;
		for (int i = 0; i < slen; i = i+plen)
		{
			string t = s.substr(i, plen);
			if (t.compare(p) != 0)
				return false;
		}
		return true;
	}
    bool repeatedSubstringPattern(string s) {
		int len = s.length();
		if (len <= 1)
			return false;
		int mid = len/2;
		for (int i = 1; i <= mid+1 && i <= len; i++)
		{
			string sub = s.substr(0,i);
			cout<<"i is:"<<i<<".		sub is:"<<sub<<endl;
			if (len % i != 0)
			{
				cout<<"continue"<<endl;
				continue;
			}
			if (checkRepeat(s, sub))
				return true;
		}
		return false;
    }
};

int main()
{
	Solution sol;
	bool ret = false;
	//ret = sol.repeatedSubstringPattern("abcabc");
	//ret = sol.repeatedSubstringPattern("aba");
	//ret = sol.repeatedSubstringPattern("abcabcabcabc");
	//ret = sol.repeatedSubstringPattern("aa");
	//ret = sol.repeatedSubstringPattern("a");
	ret = sol.repeatedSubstringPattern("ab");
	cout<<"ret is:"<<ret<<endl;
}
