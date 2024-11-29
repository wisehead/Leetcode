/*******************************************************************************
 *      file name: greatest_common_divisor_of_strings.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/07-18:50:45                              
 *  modified time: 2020/10/07-18:50:45                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string big, small;
        int len1 = str1.length();
        int len2 = str2.length();
        if (len1 == len2) 
        {
            if (str1.compare(str2) == 0) return str1;
            return string("");
        }
        if (len1 > len2)
        {
            big = str1;
            small = str2;
        } else {
            big = str2;
            small = str1;
        }
        
        int pos = big.find(small);
        if (pos != 0) return string("");
        big = big.substr(small.size(), big.size() - small.size());
        return gcdOfStrings(big, small);
    }
};
int main()
{}
