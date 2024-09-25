/*******************************************************************************
 *      file name: reverse_prefix_of_word.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/25- 9:09                                    
 * modified time: 24/09/25- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto firstOcc = word.find(ch);
        reverse(word.begin(), word.begin() + firstOcc + 1);
        return word;
    }
};
