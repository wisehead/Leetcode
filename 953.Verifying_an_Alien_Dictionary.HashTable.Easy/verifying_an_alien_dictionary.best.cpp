/*******************************************************************************
 *      file name: verifying_an_alien_dictionary.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/03-20:33:29                              
 *  modified time: 2019/02/03-20:33:29                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};
int main()
{}
