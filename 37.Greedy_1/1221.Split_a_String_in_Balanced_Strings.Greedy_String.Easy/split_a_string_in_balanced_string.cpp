/*******************************************************************************
 *      file name: split_a_string_in_balanced_string.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/21-22:09:50                              
 *  modified time: 2020/11/21-22:09:50                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool is_bs(string s) {
        int l = 0, r = 0;
        for (auto e : s) {
            if (e == 'L') l++;
            else r++;
        }
        return l == r;
    }
    
    int balancedStringSplit(string s) {
        int i = 0, cnt = 0;
        while (i < s.length()-1) {
            for (int j = i + 1; j < s.length(); j++) {
                string sub = s.substr(i, j-i+1);
                //cout<<"i"<<i<<" j:"<<j<<"   sub:"<<sub<<endl;
                if (is_bs(sub)) {
                    //cout<<"ok sub:"<<sub<<endl;
                    cnt++;
                    i = j+1;
                    break;
                }
            }
        }
        return cnt;
    }
};
int main()
{}
