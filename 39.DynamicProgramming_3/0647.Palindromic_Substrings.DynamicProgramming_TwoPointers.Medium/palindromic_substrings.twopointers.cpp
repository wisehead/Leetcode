/*******************************************************************************
 *      file name: palindromic_substrings.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/15- 1:01                                    
 * modified time: 25/01/15- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool is_palindromic(string str) {
        string str2 = str;
        reverse(str2.begin(), str2.end());

        bool ret = (str == str2);
        // cout<<"str2:"<<str2<<",ret:"<<ret<<endl;
        return ret;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string str = s.substr(i,j-i+1);
                // cout<<"i:"<<i<<",j:"<<j<<",str:"<<str<<endl;
                if (is_palindromic(str)) cnt++;
            }
        }
        return cnt;
    }
};
