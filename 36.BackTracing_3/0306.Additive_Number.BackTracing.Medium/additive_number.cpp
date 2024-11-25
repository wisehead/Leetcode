/*******************************************************************************
 *      file name: additive_number.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/28-14:12:19                              
 *  modified time: 2020/10/28-14:12:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        bool res = false;
        vector<long long> temp;
        dfs(res, temp, 0, num);
        return res;
    }
    
    void dfs(bool& res, vector<long long> &temp, int start, string s) {
        int len = s.length();
        int size = temp.size();
        if (start == len  && size > 2) {
            res = true;
            return;
        }
        for (int i = start; i < len; i++) {
            string str = s.substr(start, i-start+1);
            if (str.length()>1 && str[0] == '0') continue;
            if (str.length() > 18) continue;
            long long n =  std::stol(str);
            if (temp.size() < 2) {
                temp.push_back(n);
                dfs(res, temp, i+1, s);
                if (res) return;
                temp.pop_back();
            } else if (n == temp[size-1] + temp[size-2]) {
                temp.push_back(n);
                dfs(res, temp, i+1, s);
                if (res) return;
                temp.pop_back();
            }
        }
    }
};
int main()
{}
