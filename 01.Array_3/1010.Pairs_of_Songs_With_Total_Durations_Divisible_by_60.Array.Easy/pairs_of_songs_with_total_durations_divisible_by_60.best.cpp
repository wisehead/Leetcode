/*******************************************************************************
 *      file name: pairs_of_songs_with_total_durations_divisible_by_60.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/11-20:11:31                              
 *  modified time: 2019/07/11-20:11:31                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Intuition
Calculate the time % 60 then it will be exactly same as two sum problem.


Explanation
t % 60 gets the remainder 0 ~ 59.
We count the occurrence of each remainders in a array/hashmap c.
we want to know that, for each t, how many x satisfy (t + x) % 60 = 0.

One idea is take x % 60 = 60 - t % 60, which is valid for the most cases.
But if t % 60 = 0, x % 60 = 0 instead of 60.
60 - t % 60 will get a number in range 1 ~ 60.
(60 - t % 60) % 60 can get number in range 0 ~ 59, which is what we want.

Another idea is that x % 60 = (600 - t) % 60.
Not sure which one is more straight forward.
 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60);
        int res = 0;
        for (int t : time) {
            res += c[(600 - t) % 60];
            c[t % 60] += 1;
        }
        return res;
    }
};
int main()
{}
