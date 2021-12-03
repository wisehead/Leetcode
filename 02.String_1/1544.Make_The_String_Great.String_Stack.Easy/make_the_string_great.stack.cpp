/*******************************************************************************
 *      file name: make_the_string_great.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/03-09:58:20                              
 *  modified time: 2021/12/03-09:58:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int N = s.length();
        if (N <= 1) return s;
        for (int i = 0; i < N; i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                char top = st.top();
                if (top == s[i])
                    st.push(s[i]);
                else if (std::tolower(s[i]) == std::tolower(top)) {
                    st.pop();
                } else
                    st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};
int main()
{}
