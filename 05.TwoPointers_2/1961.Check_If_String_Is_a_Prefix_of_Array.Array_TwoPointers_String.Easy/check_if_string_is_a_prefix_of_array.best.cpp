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
        string ans = "";

        for(auto& word:words){
            ans += word;
            if(ans == s) return true;
            if(ans.length()>s.length()) return false;
        }
        return false;
    }
};
