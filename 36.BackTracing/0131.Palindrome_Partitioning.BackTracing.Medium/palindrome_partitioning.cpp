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
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        partition(res, temp, 0, s);
        return res;
    }
    
    void partition(vector<vector<string>> &res, vector<string> &temp, int start, string s) {
        int size = temp.size();
        if (size > 1) {
            string x = temp[size - 2];
            if (!is_palindrome(x)) {
                return;
            }            
        } 
        
        if (start == s.length()) {
            string x = temp[temp.size()-1];
            if (!is_palindrome(x)) {
                return;
            }         
            res.push_back(temp);
            return;
        }

        if (temp.size() == 0) {
            string s1;
            s1.push_back(s[start]);
            temp.push_back(s1);   
            partition(res, temp, start+1, s);
        } else {
            string s0 = temp.back();
            temp.pop_back();
            string str = s0;
            str.append(1, s[start]);

            temp.push_back(str);
            partition(res, temp, start+1, s);
            temp.pop_back();
                
                
            temp.push_back(s0);
            string s1(1, s[start]);
            temp.push_back(s1);
            partition(res, temp, start+1, s);
            temp.pop_back();    
        } 
    }    
    
    bool is_palindrome(string s) {
        string s0 = s;
        reverse(s0.begin(),s0.end());
        return s.compare(s0) == 0;
    }
};
int main()
{}
