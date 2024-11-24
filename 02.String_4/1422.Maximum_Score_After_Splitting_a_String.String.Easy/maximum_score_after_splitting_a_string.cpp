/*******************************************************************************
 *      file name: maximum_score_after_splitting_a_string.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/10-19:32:50                              
 *  modified time: 2021/10/10-19:32:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int maxv = -1;
        for (auto e : s) 
            if (e == '1') ones++;
        int score = ones;
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == '0')  score++;
            else score--;
            if (score > maxv) maxv = score;
        } 
        return maxv;
    }
};
int main()
{}
