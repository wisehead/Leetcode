/*******************************************************************************
 *      file name: permutation_in_string.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/31-19:56:50                              
 *  modified time: 2020/10/31-19:56:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {0};
        for(char c : s1) map[c - 'a']++;
        int j = 0, i = 0, count_chars = s1.size();
        while(j < s2.size()){
            if(map[s2.at(j) - 'a'] > 0)
                count_chars--;
            map[s2.at(j) - 'a']--;
            j++;
            if(count_chars == 0) return true;
            if(j - i == s1.size() ) {
                if (map[s2.at(i) - 'a'] >= 0)
                    count_chars++;
                map[s2.at(i) - 'a']++;
                i++;
            }
                
        }
        return false;
    }
};
int main()
{}
