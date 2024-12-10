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
            //cout<<"i:"<<i<<endl;
            if (is_vowel(word[i])) {
                ht[word[i]]++;
                for (int j = i+1; j < word.length(); j++) {
                    //cout<<"j:"<<j<<endl;
                    if (is_vowel(word[j])) {
                        ht[word[j]]++;
                        if(is_valid())cnt++;
                        //cout<<"i:"<<i<<",j:"<<j<<",cnt:"<<cnt<<endl;
                    } else {
                        //i = j;
                        break;
                    }


                }
            }
            ht.clear();
        }

        return cnt;
    }

    bool is_vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    bool is_valid() {
        // cout<<"====is_valid===="<<endl;
        // for (auto it : ht) {
        //     cout<<"it.first:"<<it.first<<",it.second:"<<it.second<<endl;
        // }
        if (ht.size() < 5) return false;
        for (auto it : ht) {
            if (it.second < 1) return false;
        }
        return true;
    }
public:
    unordered_map<char,int> ht;
};
