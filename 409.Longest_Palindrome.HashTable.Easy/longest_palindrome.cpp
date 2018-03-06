/*******************************************************************************
 *      file name: longest_palindrome.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/03/01- 3:03                                    
 *  modified time: 18/03/01- 3:03                                    
 *******************************************************************************/
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
		if (s.length() == 0)
			return 0;
		set<char> myset;
		int count = 0;
		set<char>::iterator iter;
		string::iterator it;
		for (int i = 0; i < s.length(); i++ )
		{
			cout<<"s["<<i<<"]:"<<s[i]<<endl;
			if((iter = myset.find(s[i])) != myset.end())
			{
				count++;
				myset.erase(iter);
			}
			else
				myset.insert(s[i]);
		}
		
		int is_empty = !myset.empty();
		return count*2+is_empty;
    }
};
int main()
{
	Solution sol;
	int ret = 0;
	ret = sol.longestPalindrome("abccccdd");
	cout<<"ret is:"<<ret<<endl;
}
