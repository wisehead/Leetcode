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
        int n = s1.length();
        vector<string> vec;
        vector<bool> visit(n, false);
        string temp;
        dfs(vec, visit, temp, s1);
        for (auto str : vec) {
            //cout<<"e:"<<str<<endl;
            if (s2.find(str) != string::npos) return true;
        }
        
        return false;
    }
    
    void dfs(vector<string>& res, vector<bool>& visit, string temp, string s) {
        if (temp.length() == s.length()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            if (!visit[i]) {
                visit[i] = true;
                temp.push_back(s[i]);
                dfs(res, visit, temp, s);
                temp.pop_back();
                visit[i] = false;                
            }

        }
    }
};
int main()
{}
