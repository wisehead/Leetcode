/*******************************************************************************
 *      file name: check_if_string_is_a_prefix_of_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/24- 9:09                                    
 * modified time: 24/09/24- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int len = 0, i = 0;
        string str;
        while (len < s.length() && i<words.size()) {
            str += words[i];
            len += words[i].length();
            i++;
        }
        if (str == s) return true;
        return false;
    }
};
