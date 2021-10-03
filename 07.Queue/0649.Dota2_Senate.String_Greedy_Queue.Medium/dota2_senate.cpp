/*******************************************************************************
 *      file name: dota2_senate.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/03-17:56:15                              
 *  modified time: 2021/10/03-17:56:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        int sum1 = 0;
        int sum2 = 0;
        queue<char> q;
        for (auto c : senate) {
            q.push(c);
        }
        
        while(!q.empty() && max(sum1, sum2) < q.size()) {
            int c = q.front();
            q.pop();
            if (c == 'R') {
                if (sum2) {
                    sum2--;
                } else {
                    sum1++;
                    q.push(c);
                }
            } else {// c == 'D'
                if (sum1) {
                    sum1--;
                } else {
                    sum2++;
                    q.push(c);
                }                
            }
            
        }
        if (sum1) return "Radiant";
        else return "Dire";

    }
};
int main()
{}
