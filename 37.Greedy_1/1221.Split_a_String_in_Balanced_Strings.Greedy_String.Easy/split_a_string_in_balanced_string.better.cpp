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
    int balancedStringSplit(string s) {
        int i = 0, cnt = 0;
        while (i < s.length()-1) {
            int l = 0, r = 0;
            for (int j = i; j < s.length(); j++) {
                if (s[j] == 'L') l++;
                else r++;
                //cout<<"i"<<i<<" j:"<<j<<"   sub:"<<sub<<endl;
                if (l > 0 && l == r) {
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
