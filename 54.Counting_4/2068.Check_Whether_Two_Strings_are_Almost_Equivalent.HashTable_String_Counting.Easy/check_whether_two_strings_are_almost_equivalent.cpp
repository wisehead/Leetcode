/*******************************************************************************
 *      file name: check_whether_two_strings_are_almost_equivalent.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/10-12:12                                    
 * modified time: 24/12/10-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.length();
        vector<char> v1(26,0);
        // vector<char> v2(26,0);
        for (auto c : word1) {
            v1[c-'a']++;
        }
        for (auto c : word2) {
            v1[c-'a']--;
        }
        int ret = 0;
        for (int i = 0; i < 26; i++) {
            ret = max(ret, abs(v1[i]));
        }
        return ret<= 3;
    }
};
