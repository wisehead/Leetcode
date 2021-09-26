/*******************************************************************************
 *      file name: remove_all_adjacent_duplicates.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/06-19:44:28                              
 *  modified time: 2020/10/06-19:44:28                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0, n = s.length();
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[i]) // count = 2
                i -= 2;
        }
        return s.substr(0, i);
    }
};
int main()
{}
