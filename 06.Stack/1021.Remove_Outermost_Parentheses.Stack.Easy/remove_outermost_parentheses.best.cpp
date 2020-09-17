/*******************************************************************************
 *      file name: remove_outermost_parentheses.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/17-09:47:11                              
 *  modified time: 2020/09/17-09:47:11                              
 *******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
    }
};
int main()
{}
