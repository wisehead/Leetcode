/*******************************************************************************
 *      file name: remove_palidromic_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/01-16:53:52                              
 *  modified time: 2021/08/01-16:53:52                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
    }
};
int main()
{}
