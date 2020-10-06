/*******************************************************************************
 *      file name: remove_all_adjacent_duplicates.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/06-19:44:28                              
 *  modified time: 2020/10/06-19:44:28                              
 *******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (auto e: S) {
            if (!st.empty() && st.top() == e)
                st.pop();
            else
                st.push(e);
        }
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            res.insert(0,1,c);
        }
        return res;
    }
private:
    stack<int> st;
};
int main()
{}
