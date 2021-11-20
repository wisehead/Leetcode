/*******************************************************************************
 *      file name: check_if_a_word_occurs_as_a_prefix_of_any_word_in_a_sentence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/20-11:58:14                              
 *  modified time: 2021/11/20-11:58:14                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence = " " + sentence; 
        string temp = " " + searchWord;
        int index = sentence.find(temp);
        if (index == string::npos) return -1;
        int space = 0;
        for (int i = 0; i <= index; i++) 
            if (sentence[i] == ' ') space++;
        return space;
    }
};
int main()
{}
