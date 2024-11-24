/*******************************************************************************
 *      file name: find_the_kth_character_in_string_game_I.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/24-11:11                                    
 * modified time: 24/11/24-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        return f(str,k);
    }

    char f(string str, int k) {
        if (k <= str.length()) return str[k-1];
        str = transform(str);
        return f(str,k);
    }

    string transform(string str) {
        string res = str;
        for (auto c : str) {
            c += 1;
            if (c == 'z' +1) c = 'a';
            res += c;
        }
        return res;
    }
};
