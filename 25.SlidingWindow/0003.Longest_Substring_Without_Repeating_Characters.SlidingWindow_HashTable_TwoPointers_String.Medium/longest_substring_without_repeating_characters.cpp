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
        set<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (st.count(s[i]) ) {
                int size = st.size();
                ret = max(size, ret);
                for (int j = i - size; j < i; ++j) {
                    if (s[j] == s[i]) break;
                    st.erase(s[j]);
                }
            } else
                st.insert(s[i]);     
        }
        if (st.size() > ret) ret = st.size();
        return ret;
        
    }
};
int main()
{}
