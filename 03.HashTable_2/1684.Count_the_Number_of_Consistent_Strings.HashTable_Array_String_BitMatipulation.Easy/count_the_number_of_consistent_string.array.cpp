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
        int array[27] = {0};
        int cnt = 0;
        
        for (auto c : allowed) 
            array[c - 'a'] = 1;
        
        for (auto w : words) {
            cnt++;
            for (auto c : w) {
                if (!array[c-'a']) {
                    cnt--;
                    break;
                }
            }
            
        }
        return cnt;
    }
};
