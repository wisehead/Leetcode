/*******************************************************************************
 *      file name: valid_palindrome.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/20-11:11                                    
 * modified time: 17/11/20-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isAlpha(char c)
	{
		return ((c >='a' && c<='z') ||  (c >='A' && c<='Z') || (c >='0' && c<='9'));
	}
    bool isPalindrome(string s) {
		cout<<"input s:"<<s<<endl;
		int len = s.length();
		if (len == 0)
			return true;
		string::iterator it;
		for (it = s.begin(); it != s.end(); )
		{
			if (!isAlpha(*it))
			{
				s.erase(it);
			}
			else
				it++;
		}
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout<<"out s:"<<s<<endl;
		string s2 = s;
		reverse(s2.begin(), s2.end());
		cout<<"out s2:"<<s2<<endl;
		return (!s.compare(s2));
    }
};

int main()
{
	Solution sol;
	bool ret = false;
	ret = sol.isPalindrome("0P");
	cout<<"the result is:"<<ret<<endl;
}
