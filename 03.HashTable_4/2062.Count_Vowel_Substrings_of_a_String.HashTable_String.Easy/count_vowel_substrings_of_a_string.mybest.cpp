/*******************************************************************************
 *      file name: count_vowel_substrings_of_a_string.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/04-12:12                                    
 * modified time: 24/12/04-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countVowelSubstrings(string word) {
        int cnt = 0;
        for (int i = 0; i < word.length(); i++) {
            if (is_vowel(word[i])) {
                ht[word[i]]++;
                int j = i+1;
                int old_i = i;
                for (; j < word.length(); j++) {
                    if (is_vowel(word[j])) {
                        ht[word[j]]++;
                        if(is_valid())cnt++;
                    } else {
                        i = j;
                        break;
                    }
                }
                if (j == word.length()) {
                    i = j;
                }
                j--;
                cnt = fun(old_i,j,word,cnt);
            }
            ht.clear();
        }

        return cnt;
    }

    int fun(int old_i, int old_j, string word, int cnt) {
        unordered_map<char,int> old_ht = ht;
        for (int i = old_i+1; i <= old_j-4; i++) {
            old_ht[word[i-1]]--;
            ht = old_ht;

            for (int k=old_j; k >= i+4; k--) {
                if (!is_vowel(word[k]))break;
                if(is_valid()) {
                    cnt++;
                    ht[word[k]]--;
                }
                else break;
            }
        }
        return cnt;
    }

    bool is_vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    bool is_valid() {
        if (ht.size() < 5) return false;
        for (auto it : ht) {
            if (it.second < 1) return false;
        }
        return true;
    }
public:
    unordered_map<char,int> ht;
};
