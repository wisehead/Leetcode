/*******************************************************************************
 *      file name: replace_all_question_marks_to_avoid_consecutive_repeating_characters.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/26-19:41:41                              
 *  modified time: 2021/12/26-19:41:41                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string modifyString(string s) {
        s = '1' + s + '1';
        int N = s.length();
        for (int i = 1; i < N-1; i++) {
            if (s[i] == '?') {
                char c = 'a';
                for (; c <= 'z'; c++) {
                    if (c != s[i-1] && c != s[i+1]) break;
                }
                s[i] = c;
            }
        }
        string res = s.substr(1, N-2);
        return res;
    }
};
int main()
{}
