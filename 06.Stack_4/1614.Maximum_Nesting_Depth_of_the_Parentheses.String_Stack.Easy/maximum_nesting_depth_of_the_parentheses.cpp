/*******************************************************************************
 *      file name: maximum_nesting_depth_of_the_parentheses.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/08-11:45:46                              
 *  modified time: 2022/01/08-11:45:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        //cout<<"s:"<<s<<endl;
        if (mm.count(s)) return mm[s];
        stack<int> st;
        int depth = 0;
        int N = s.length();
        for (int i = 0; i < N; i++) {
            char c = s[i];
            if (c == '(') {
                st.push(i);
            } else if (c == ')') {
                int x = st.top();
                st.pop();
                int ret = maxDepth(s.substr(x+1, i - x-1));
                if (ret+1 > depth) depth = ret + 1;
            }
        }
        mm[s] = depth;
        return depth;
    }
private:
    map<string, int> mm;
};
int main()
{}
