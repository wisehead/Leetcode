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
Thanks @lee215 for his code and video.
Since lots of people ask to explain the elegant solution, let me rewrite his code as follows:

Denote A[i] + i - j as cur with an initialization value of 0
 */
class Solution {
public:
    public int maxScoreSightseeingPair(int[] A) {
        int res = 0, cur = 0;
        for (int i = 0, j = 0; j < A.length; ++j) {
            res = Math.max(res, cur + A[j]);
            // the follows use j + 1 instead of j, due to j's increment by 1 in next iteration.
            // the if conditional is same as: if (cur - 1 < A[j] - 1), which can be simplified as: if (cur < A[j]). 
            if (A[i] + i - (j + 1) < (A[j] + j) - (j + 1)) {
                // update both i & j for cur in next iteration.
                i = j;
                cur = (A[i] + i) - (j + 1); // this is actually A[j] - 1
            }else {
                // update only j to (j + 1) but not i for cur in next iteration.								 
                cur = (A[i] + i) - (j + 1); // (A[i] + i - j) - 1, actually cur - 1.
            }
        }
        return res;
    }
};
int main()
{}
