/*******************************************************************************
 *      file name: check_if_word_equals_summation_of_two_words.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/18- 9:09                                    
 * modified time: 24/09/18- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {

        string temp1;
        for (int i = 0; i < firstWord.length(); i++) {
            firstWord[i] = (firstWord[i] - 'a' + '0');
        }
        //cout<<"firstWord:"<<firstWord<<endl;
        int first_num = std::stoi(firstWord);
        //cout<<"first_num:"<<first_num<<endl;

        for (int i = 0; i < secondWord.length(); i++) {
            secondWord[i] = secondWord[i] - 'a' + '0';
        }
        //cout<<"secondWord:"<<secondWord<<endl;
        int second_num = std::stoi(secondWord);
        //cout<<"second_num:"<<second_num<<endl;

        for (int i = 0; i < targetWord.length(); i++) {
            targetWord[i] = (targetWord[i] - 'a' + '0');
        }
        int target_num = std::stoi(targetWord);
        return first_num + second_num == target_num;
    }
};
