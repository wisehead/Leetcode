/*******************************************************************************
 *      file name: backspace_string_compare.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/18-16:59:07                              
 *  modified time: 2018/12/18-16:59:07                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	string processString(string str) {
		//cout<<"before process str is:"<<str<<endl;
		int len = str.length();
		string::iterator it;
		for (it=str.begin(); it != str.end(); it++)
		{
			//cout<<"*it:"<<*it<<endl;
			if(*it == '#')
			{
                int num = 2;
                if(it == str.begin())
                {
                    num = 1;
                    it++;
                }
				it--;
				it = str.erase(it, it+num);
				//cout<<"in process str is:"<<str<<endl;
				it--;
			}
		}
		//cout<<"after process str is:"<<str<<endl;
		return str;
	}
    bool backspaceCompare(string S, string T) {
		string ss = processString(S);
		string tt = processString(T);
		return (ss.compare(tt) == 0 );
    }
};
int main()
{
	Solution sol;
	string S = "aab##";
	string T = "ac#d#";
	sol.backspaceCompare(S,T);
}
