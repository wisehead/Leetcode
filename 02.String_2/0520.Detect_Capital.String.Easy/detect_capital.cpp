/*******************************************************************************
 *      file name: detect_capital.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/21-18:24:15                              
 *  modified time: 2018/08/21-18:24:15                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	bool is_upper(char c) {
		return (c <= 'Z');
	}

    bool detectCapitalUse(string word) {
		int len = word.length();
		bool first_upper = false;
		for (int i=0; i < len; i++)
		{
			if (i == 0)
			{
				first_upper = is_upper(word[i]);
				continue;
			}
			if (first_upper)
			{
				cout<<i<<"	:"<<word[i]<<" is_upper:"<<is_upper(word[i])<<endl;
				if (i == 1)
					continue;
				if(is_upper(word[i]) != is_upper(word[i-1]))
					return false;
			}
			else
			{
				if (is_upper(word[i]))
					return false;
			}
		}
		return true;
    }
};
int main()
{
	Solution sol;
	bool ret = false;
	string str = "FlaG";
	ret = sol.detectCapitalUse(str);
	cout<<"ret for "<<str<<" is:"<<ret<<endl;
}
