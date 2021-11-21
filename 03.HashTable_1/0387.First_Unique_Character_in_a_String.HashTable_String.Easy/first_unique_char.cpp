/*******************************************************************************
 *      file name: first_unique_char.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/08- 1:01                                    
 *  modified time: 18/01/08- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
		map<char, int> m;
		int size = s.length();
		for (int i=0; i<size; i++)
		{
			++m[s[i]];
		}
		for (int j=0; j<size; j++)
		{
			if (m[s[j]] == 1)
				return j;
		}
		return -1;
    }
};
int main()
{
	Solution sol;
	//string s = "leetcode";
	//string s = "loveleetcode";
	string s = "";
	int ret = 0;
	ret = sol.firstUniqChar(s);
	cout<<"ret for "<<s<<" is:"<<ret<<endl;
}
