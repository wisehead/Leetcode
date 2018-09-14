/*******************************************************************************
 *      file name: valid_palindrome_II.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/14-22:24:54                              
 *  modified time: 2018/09/14-22:24:54                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
		//cout<<"input s:"<<s<<endl;
		int len = s.length();
		if (len == 0)
			return true;
		//cout<<"out s:"<<s<<endl;
		string s2 = s;
		reverse(s2.begin(), s2.end());
		//cout<<"out s2:"<<s2<<endl;
		return (!s.compare(s2));
    }

    bool validPalindrome(string s) {
		int len = s.length();
		int i = 0, j = len - 1;
		while (i < j)
		{
			if (s[i] == s[j])
			{
				i++; j--;
			}
			else
			{ 
                if (i+1 == j) return true;
                string s1 = s.substr(i+1, j-i);
				string s2 = s.substr(i, j-i);
				return (isPalindrome(s1) || isPalindrome(s2));
			}
		}
		return true;
    }
};
int main()
{}
