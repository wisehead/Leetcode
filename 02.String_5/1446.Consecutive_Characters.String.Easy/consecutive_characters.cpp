/*******************************************************************************
 *      file name: consecutive_characters.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/20-10:30:46                              
 *  modified time: 2021/11/20-10:30:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxPower(string s) {
        int N = s.length();
        int power = 0;
        for (int i = 0; i < N;) {
            int cnt = 1;
            int j = 0;
            for (j = i+1; j < N; j++) {
                if (s[j] == s[i]) cnt++;
                else break;
            }
            i = j;
            if (cnt > power) power = cnt;
        }
        return power;
    }
};
int main()
{}
