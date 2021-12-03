/*******************************************************************************
 *      file name: make_the_string_great.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/03-09:58:20                              
 *  modified time: 2021/12/03-09:58:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        int cnt = 0;
        do {
            cnt = 0;
            int N = s.length();
            for (int i = 0; i < N-1; i++) {
                if (s[i] == s[i+1]) continue;
                char next = std::tolower(s[i+1]);
                if (std::tolower(s[i]) == next) {
                    s.erase(i,2);
                    cnt++;
                    break;
                }
            }
        } while (cnt);
        return s;
    }
};
int main()
{}
