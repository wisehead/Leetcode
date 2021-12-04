/*******************************************************************************
 *      file name: split_a_string_in_balanced_string.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/21-22:09:50                              
 *  modified time: 2020/11/21-22:09:50                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cnt = 0;
        for (const auto& c : s) {
            cnt += c == 'L' ? 1 : -1;
            if (cnt == 0) ++res;
        }
        return res;        
    }
};
int main()
{}
