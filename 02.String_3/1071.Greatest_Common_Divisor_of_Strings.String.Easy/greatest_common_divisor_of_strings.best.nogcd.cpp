/*******************************************************************************
 *      file name: greatest_common_divisor_of_strings.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/07-18:50:45                              
 *  modified time: 2020/10/07-18:50:45                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        if (str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
int main()
{}
