/*******************************************************************************
 *      file name: combinations.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/24-10:53:54                              
 *  modified time: 2020/10/24-10:53:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    set<set<int>> c(int n, int k) {
        set<set<int>> st;
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                set<int> s;
                s.insert(i);
                st.insert(s);
            }
            return st;
        }
        
        set<set<int>> s0 = c(n, k-1);
        set<set<int>>::iterator it;
        for (it = s0.begin(); it != s0.end(); it++) {
            
            for (int i = 1; i <= n; i++) {
                set<int> s2 = *it;              
                s2.insert(i);
                if (s2.size() == k)
                    st.insert(s2);
            }
        }
        /*
        for (it = st.begin(); it != st.end(); it++) {
            set<int> s = *it;
            set<int>::iterator it2;
            for (it2 = s.begin(); it2 != s.end(); it2++) 
                cout<<" "<<*it2;
            cout<<endl;
        }
        */
        return st;
    }
    vector<vector<int>> combine(int n, int k) {
        set<set<int>> st = c(n, k);
        vector<vector<int>> res;
        set<set<int>>::iterator it;
        for (it = st.begin(); it != st.end(); it++) {
            set<int> s0 = *it;
            vector<int> v(s0.begin(), s0.end());
            res.push_back(v);
        }
        return res;
    }
};
int main()
{}
