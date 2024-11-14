/*******************************************************************************
 *      file name: minimum_moves_to_convert_string.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/14-11:11                                    
 * modified time: 24/11/14-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length();
        int cnt = 0, i = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == 'O' ) continue;
            cnt++;
            i += 2;
        }
        return cnt;
    }
};
