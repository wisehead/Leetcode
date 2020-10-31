/*******************************************************************************
 *      file name: permutation_in_string.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/31-19:56:50                              
 *  modified time: 2020/10/31-19:56:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<string> vec;
        dfs(vec, s1, s1.length());
        for (auto str : vec) {
            //cout<<"e:"<<str<<endl;
            if (s2.find(str) != string::npos) return true;
        }
        
        return false;
    }
    
    void dfs(vector<string>& res, string s, int n) {
        if (n > s.length()) return;
        if (n == 1) {
            string str(1, s[0]);
            res.push_back(str);
        }
        
        vector<string> vec;
        dfs(vec, s, n-1);
        for (int i = 0; i < n; i++) {
            for (auto str : vec) {
                str.insert(str.begin()+i,  s[n-1]);
                res.push_back(str);
            }
        }
    }
};
int main()
{}
