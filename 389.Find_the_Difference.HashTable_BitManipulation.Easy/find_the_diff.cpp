/*******************************************************************************
 *      file name: find_the_diff.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/08- 1:01                                    
 *  modified time: 18/01/08- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
		int len_s = s.length();
		int len_t = t.length();
		char ret = s[0];
		for (int i=1 ; i<len_s; i++)
		{
			ret = ret ^ s[i]; 
			cout<<"s ret is:"<<ret<<endl;
		}
		for (int j=0 ; j<len_t; j++)
		{
			ret = ret ^ t[j]; 
			cout<<"t ret is:"<<ret<<endl;
		}
		return ret;
    }
};
int main()
{
	Solution sol;
	string s = "abcd";
	string t = "abcde";
	char ret = sol.findTheDifference(s, t);
	cout<<"ret for "<<s<<" and "<<t<<"	is:"<<ret<<endl;
}
