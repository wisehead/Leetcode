/*******************************************************************************
 *      file name: palindrome_partitioning.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/27-18:32:01                              
 *  modified time: 2020/10/27-18:32:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
/*The Idea is simple: loop through the string, check if substr(0, i) is palindrome.
 If it is, recursively call dfs() on the rest of sub string: substr(i+1, length). keep the current palindrome partition so far in the 'path' argument of dfs(). When reaching the end of string, add current partition in the result.

*/
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
int main()
{}
