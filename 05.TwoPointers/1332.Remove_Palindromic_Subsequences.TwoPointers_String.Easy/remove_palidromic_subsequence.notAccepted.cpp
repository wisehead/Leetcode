/*******************************************************************************
 *      file name: remove_palidromic_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/01-16:53:52                              
 *  modified time: 2021/08/01-16:53:52                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool is_palidrome(string s) {
        if (s.length() <= 1) return true;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
    
    int removePalindromeSub(string s) {
        int len = s.length();
        if (len == 0) return 0;
        if (len == 1) return 1;
        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == s[0] && is_palidrome(s.substr(0, i+1)))
            {
                return 1+removePalindromeSub(s.substr(i+1));
            }
        }
        return 1;
    }
};
int main()
{}
