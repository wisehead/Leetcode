/*******************************************************************************
 *      file name: largest_odd_number_in_string.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/22- 9:09                                    
 * modified time: 24/09/22- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length()-1; i >=0; i--) {
            if (num[i] % 2) {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
