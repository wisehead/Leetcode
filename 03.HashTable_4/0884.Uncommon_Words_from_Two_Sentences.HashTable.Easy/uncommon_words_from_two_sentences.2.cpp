/*******************************************************************************
 *      file name: uncommon_words_from_two_sentences.2.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/17- 9:09                                    
 * modified time: 24/09/17- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mm;
        vector<string> res;
        vector<string> tokens1 = splitString(s1);
        vector<string> tokens2 = splitString(s2);
        tokens1.insert(tokens1.end(), tokens2.begin(), tokens2.end());
        for (auto str : tokens1) {
            if (mm.count(str)) {
                mm[str]++;
            } else {
                mm[str] = 1;
            }
        }
        for (auto it = mm.begin(); it != mm.end(); it++) {
            if (it->second == 1) {
                res.push_back(it->first);
            }
        }
        return res;
    }

    std::vector<std::string> splitString(const std::string &str) {
        std::vector<std::string> tokens;
        std::istringstream iss(str);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }
};
