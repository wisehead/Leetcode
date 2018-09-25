/*******************************************************************************
 *      file name: longest_word_in_dictionary.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/25-10:19:57                              
 *  modified time: 2018/09/25-10:19:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    string longestWord(vector<string>& words) {
		int len = words.size();
		set<string> ss;
		set<string>::iterator it;
		int max = 0;
		string maxstr;
		for (int i = 0; i < len; i++)
		{
			string str = words[i];
			int ll = str.length();
			if (ll > 1)
			{
				it = ss.find(str.substr(0, ll - 1));
				if (it != ss.end())
				{
					ss.insert(str);
					if (ll > max) {
						max = ll;
						maxstr = str;
					}
				}
			}
			else if ( ll == 1)
			{
				ss.insert(str);
				if (ll > max) {
					max = ll;
					maxstr = str;
				}
			}
		}
		return maxstr;
    }
};
int main()
{}
