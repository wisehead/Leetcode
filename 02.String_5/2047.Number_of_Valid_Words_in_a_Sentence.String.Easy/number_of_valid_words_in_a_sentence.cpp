/*******************************************************************************
 *      file name: number_of_valid_words_in_a_sentence.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/18-11:11                                    
 * modified time: 24/11/18-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countValidWords(string sentence) {
        int cnt = 0;
        vector<string> tokens = splitStringBySpace(sentence);
        for (auto token : tokens) {
            if (!is_have_digits(token) && is_hyphen_valid(token) && is_punctuation_valid(token)) {
                cnt++;
                //cout<<"token:"<<token<<"    cnt:"<<cnt<<endl;
            }
        }
        return cnt;
    }

    vector<string> splitStringBySpace(const string& input) {
        vector<string> tokens;
        stringstream ss(input);
        string token;

        while (ss >> token) {
            tokens.push_back(token);
        }

        return tokens;
    }

    bool is_have_digits(string str) {
        for (auto c : str) {
            if (c <= '9' && c >= '0') return true;
        }
        return false;
    }

    bool is_letter(char c) {
        return (c >= 'a' && c <= 'z');
    }

    bool is_hyphen_valid(string str) {
        int cnt = 0;
        int len = str.length();
        if (len == 0) return true;
        if (str[0] == '-' || str[len-1] == '-') return false;
        for (int i = 1; i < len-1; i++) {
            if (str[i] == '-' ) {
                if (is_letter(str[i-1]) && is_letter(str[i+1])) cnt++;
                else return false;
            }

        }
        return cnt <= 1;
    }

    bool is_punctuation(char c) {
        if (c == '!' || c == '.' || c == ',') return true;
        return false;
    }

    bool is_punctuation_valid(string str) {
        int cnt = 0;
        int len = str.length();
        if (len == 0) return true;
        for (int i = 0; i < len; i++) {
            if (is_punctuation(str[i])) {
                if (i != len-1) return false;
                cnt++;
            }
        }
        return cnt <= 1;
    }
};
