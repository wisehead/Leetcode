/*******************************************************************************
 *      file name: count_the_number_of_consistent_string.cpp                                               
 *         author: hui chen. (c) 22                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 22/10/27-10:10                                    
 * modified time: 22/10/27-10:10                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;
        int cnt = 0;
        for (auto e : allowed) {
            s.insert(e);
        }

        for (auto w : words) {
            int wlen = w.length();
            int i = 0;
            for (i = 0; i < wlen; i++) {
                if (!s.count(w[i])) break;
            }
            if (i == wlen) cnt++;
        }
        return cnt;
    }
};
