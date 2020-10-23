/*******************************************************************************
 *      file name: longest_substring_without_repeating_characters.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/23-09:53:24                              
 *  modified time: 2020/10/23-09:53:24                              
 *******************************************************************************/
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            set<char> st;
            for (int j = i; j < len; j++) {
                if (st.count(s[j]) ) {
                    ret = max((int)st.size(), ret);
                    break;
                }
                st.insert(s[j]);
                
            }
            if (st.size() > ret) ret = st.size();
        }
        return ret;
        
    }
};
int main()
{}
