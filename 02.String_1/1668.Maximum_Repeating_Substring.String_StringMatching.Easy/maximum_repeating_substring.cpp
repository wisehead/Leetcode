/*******************************************************************************
 *      file name: maximum_repeating_substring.cpp                                               
 *         author: hui chen. (c) 22                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 22/10/27-10:10                                    
 * modified time: 22/10/27-10:10                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int word_len =  word.length();
        int count = 0;
        int ret = 0;
        
        for (int i = 0; i < n +1 - word_len; i++) {
            if (count > ret) ret = count;
            count = 0;
            for (int j = i; j < n +1 - word_len; j++) {
                if (!sequence.compare(j, word_len, word)) {
                    count++;
                    j += (word_len-1);
                } else {
                    break;
                }
            }
        }
        if (count > ret) ret = count;
        return ret;
    }
};
