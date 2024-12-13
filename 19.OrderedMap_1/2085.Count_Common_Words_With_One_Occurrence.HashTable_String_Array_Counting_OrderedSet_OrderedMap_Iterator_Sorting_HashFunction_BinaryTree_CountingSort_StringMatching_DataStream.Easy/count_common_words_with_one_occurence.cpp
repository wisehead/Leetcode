/*******************************************************************************
 *      file name: count_common_words_with_one_occurence.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/13-12:12                                    
 * modified time: 24/12/13-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> ht1;
        unordered_map<string, int> ht2;
        int cnt = 0;
        for (auto str : words1) {
            ht1[str]++;
        }
        for (auto str : words2) {
            ht2[str]++;
        }
        for (auto it : ht1) {
            if (it.second == 1 && ht2[it.first] == 1) cnt++;
        }
        return cnt;
    }
};
