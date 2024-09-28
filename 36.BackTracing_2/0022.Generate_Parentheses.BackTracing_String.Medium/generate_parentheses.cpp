/*******************************************************************************
 *      file name: generate_parentheses.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/23-14:01:47                              
 *  modified time: 2020/10/23-14:01:47                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<string> fun(int n) {
        vector<string> res;
        if (n == 0) {
            res.push_back(string(""));
            return res;
        }
        vector<string> vec = fun(n-1);
        for (auto e : vec) {
            string s = "(" + e;
            res.push_back(s);
            s = ")" + e;
            res.push_back(s);
        }
        return res;
    }
    bool check(string str) {
        stack<char> st;
        for (auto e : str) {
            if (e == '(') st.push('(');
            else {
                if (st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec = fun(n*2);
        vector<string> res;
        for (auto e : vec) {
            if (check(e)) res.push_back(e); 
        }
        return res;
    }
};
int main()
{}
