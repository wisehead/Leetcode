/*******************************************************************************
 *      file name: mini_parser.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/09-21:21:30                              
 *  modified time: 2022/01/09-21:21:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        //cout<<"deserialize s:"<<s<<endl;
        int N = s.length();
        if (N >= 2 && s[0] == '[' && s[N-1] == ']') {
            NestedInteger ret;
            NestedInteger tmp = fun(s.substr(1,N-2));
            return tmp;

        }
        return fun(s).getList().front();
    }

    NestedInteger fun(string s) {
        function<bool(char)> isnumber = [](char c){ return (c == '-') || isdigit(c); };

        //cout<<"fun s:"<<s<<endl;
        NestedInteger ret;
        int N = s.length();
        if (N == 0) return ret;
        stack<int> st;

        for (int i = 0; i < N; i++) {
            char c = s[i];
            if (isnumber(c) && st.empty()) {
                auto it2 = find_if_not(s.begin()+i, s.end(), isnumber);
                int val = stoi(string(s.begin()+i, it2));
                ret.add(NestedInteger(val));
                i = it2-s.begin()-1;
                continue;
            }

            if (s[i] == '[') {
                st.push(i);
            } else if (s[i] == ']') {
                int x = st.top();
                st.pop();
                if (st.empty()) {
                    string ss = s.substr(x+1, i-x-1);
                    NestedInteger tmp = fun(ss);
                    ret.add(tmp);
                }
            }
        }
        return ret;
    }

};
int main()
{}
