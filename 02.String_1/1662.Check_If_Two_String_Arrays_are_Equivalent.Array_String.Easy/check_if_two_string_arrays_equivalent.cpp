/*******************************************************************************
 *      file name: check_if_two_string_arrays_equivalent.cpp                                               
 *         author: hui chen. (c) 22                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 22/10/15-10:10                                    
 * modified time: 22/10/15-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (auto s : word1) s1 += s;
        for (auto s : word2) s2 += s;
        return s1 == s2;
    }
};
int main() {}
