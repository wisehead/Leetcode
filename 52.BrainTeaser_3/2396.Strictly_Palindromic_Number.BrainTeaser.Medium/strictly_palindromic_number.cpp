/*******************************************************************************
 *      file name: strictly_palindromic_number.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/17- 1:01                                    
 * modified time: 25/01/17- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    string trans(int n, int base) {
        string str;
        while (n) {
            int x = n % base;
            str = to_string(x) + str;
            n = n/base;
        }
        return str;
    }
    bool is_palin(string str) {
        int n = str.length();
        int left = 0;
        int right = n-1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n-2; i++) {
            string str = trans(n, i);
            if (!is_palin(str)) return false;
        }
        return true;
    }
};
