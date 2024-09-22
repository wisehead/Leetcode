/*******************************************************************************
 *      file name: redistribute_characters_to_make_all_strings_equal.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/22- 9:09                                    
 * modified time: 24/09/22- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> vec(26,0);
        int n = words.size();
        for (auto word : words) {
            for (auto c : word) {
                vec[c-'a']++;
            }
        }
        for (auto m : vec) {
            if (m % n != 0) return false;
        }
        return true;
    }
};
