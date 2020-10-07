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
    string gcdOfStrings(const string& s1, const string& s2)
    {
        return (s1 + s2 == s2 + s1)  
            ? s1.substr(0, __gcd(s1.length(), s2.length()))
            : "";
    }
};
int main()
{}
