/*******************************************************************************
 *      file name: best_sightseeing_pair.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/14-17:37:01                              
 *  modified time: 2019/07/14-17:37:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Intuition:
Count the current best score in all previous sightseeing spot.
Note that, as we go further, the score of previous spot decrement.

Explanation
cur will record the best score that we have met.
We iterate each value a in the array A,
update res by max(res, cur + a)

Also we can update cur by max(cur, a).
Note that when we move forward,
all sightseeing spot we have seen will be 1 distance further.

So for the next sightseeing spot cur = Math.max(cur, a) **- 1**

It's kinds of like, "A near neighbor is better than a distant cousin."

Time Complexity:
One pass, O(N) time, O(1) space
 */
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0, cur = 0;
        for (int a: A) {
            res = max(res, cur + a);
            cur = max(cur, a) - 1;
        }
        return res;
    }
};
int main()
{}
