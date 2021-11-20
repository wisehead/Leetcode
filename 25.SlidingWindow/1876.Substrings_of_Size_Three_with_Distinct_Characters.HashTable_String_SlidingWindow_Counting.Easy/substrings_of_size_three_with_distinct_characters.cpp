/*******************************************************************************
 *      file name: substrings_of_size_three_with_distinct_characters.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/10-09:22:50                              
 *  modified time: 2021/08/10-09:22:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countGoodSubstrings(string s) {
        int sum = 0;
        int N = s.length();
        for (int i = 0; i < N - 2; i++) {
            if (s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]) ++sum;
        }
        return sum;
    }
};
int main()
{}
