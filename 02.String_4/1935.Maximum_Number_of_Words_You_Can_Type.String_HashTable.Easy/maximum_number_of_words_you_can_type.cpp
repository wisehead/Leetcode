/*******************************************************************************
 *      file name: maximum_number_of_words_you_can_type.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/10/20-10:10                                    
 * modified time: 24/10/20-10:10                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> tokens = splitStringBySpace(text);
        set<char> mySet;
        int ret = 0;
        for (auto c : brokenLetters) {
            mySet.insert(c);
        }
        for (auto token : tokens) {
            bool hit = false;
            for (auto c : token) {
                if (mySet.count(c)) {
                    hit = true;
                    break;
                }
            }
            if (!hit) ret++;
        }
        return ret;
    }
    std::vector<std::string> splitStringBySpace(const std::string &str) {
        std::istringstream iss(str);
        vector<string> tokens;
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
