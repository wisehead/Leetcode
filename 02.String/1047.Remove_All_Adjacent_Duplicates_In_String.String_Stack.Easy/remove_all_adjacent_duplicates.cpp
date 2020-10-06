/*******************************************************************************
 *      file name: remove_all_adjacent_duplicates.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/06-19:44:28                              
 *  modified time: 2020/10/06-19:44:28                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string fun(string str) {
        for (int i = str.length() - 1; i > 0 ; i--) {
            if (str[i] == str[i-1]) {
                str.erase(i-1,2);
            }    
        }
        return str;
    }
    string removeDuplicates(string S) {
        string s;
        int last_len = -1;
        while (last_len != s.length())
        {
            last_len = s.length();
            s = fun(S);
            //cout<<"s:"<<s<<endl;
        }
        return s;
    }
};
int main()
{}
