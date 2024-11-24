/*******************************************************************************
 *      file name: reformat_the_string.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/07-18:36:20                              
 *  modified time: 2021/10/07-18:36:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string reformat(string s) {
        string alpha;
        string digits;
        string res;
        for (char c : s) {
            if (c >= '0' && c <= '9') 
                digits += c;
            else 
                alpha += c;
        }
        
        int len_a = alpha.length();
        int len_d = digits.length();
        if (abs(len_a - len_d) > 1) return "";
        if (len_a == len_d) {
            for (int i = 0; i < len_a; i++) {
                res += alpha[i];
                res += digits[i];
            }
        } else if (len_a > len_d) {
            res += alpha[len_a-1];
            for (int i = 0; i < len_d; i++) {
                res += digits[i];
                res += alpha[i];
            }
        } else {
            res += digits[len_d-1];
            for (int i = 0; i < len_a; i++) {
                res += alpha[i];
                res += digits[i];
            }            
        }
        return res;
    }
};
int main()
{}
