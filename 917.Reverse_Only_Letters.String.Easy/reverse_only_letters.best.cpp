/*******************************************************************************
 *      file name: reverse_only_letters.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/22-11:05:23                              
 *  modified time: 2019/01/22-11:05:23                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string S) {
        for (int i = 0, j = S.length() - 1; i < j; ++i, --j) {
            while (i < j && !isalpha(S[i])) ++i;
            while (i < j && !isalpha(S[j])) --j;
            swap(S[i], S[j]);
        }
        return S;
    }
};
int main()
{}
