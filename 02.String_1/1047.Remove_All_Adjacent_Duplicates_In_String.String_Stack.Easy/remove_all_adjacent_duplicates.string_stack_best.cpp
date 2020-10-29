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
    string removeDuplicates(string S) {
        string res = "";
        for (char& c : S)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;
    }
};
int main()
{}
