/*******************************************************************************
 *      file name: moving_stones_until_consecutive_II.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/05-15:20:24                              
 *  modified time: 2020/01/05-15:20:24                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Lower Bound
As I mentioned in my video last week,
in case of n stones,
we need to find a consecutive n positions and move the stones in.

This idea led the solution with sliding windows.

Slide a window of size N, and find how many stones are already in this window.
We want moves other stones into this window.
For each missing stone, we need at least one move.

Generally, the number of missing stones and the moves we need are the same.
Only one corner case in this problem, we need to move the endpoint to no endpoint.

For case 1,2,4,5,10,
1 move needed from 10 to 3.

For case 1,2,3,4,10,
2 move needed from 1 to 6, then from 10 to 5.


Upper Bound
We try to move all stones to leftmost or rightmost.
For example of to rightmost.
We move the A[0] to A[1] + 1.
Then each time, we pick the stone of left endpoint, move it to the next empty position.
During this process, the position of leftmost stones increment 1 by 1 each time.
Until the leftmost is at A[n - 1] - n + 1.


Complexity
Time of quick sorting O(NlogN)
Time of sliding window O(N)
Space O(1)
 */
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        sort(A.begin(), A.end());
        int i = 0, n = A.size(), low = n;
        int high = max(A[n - 1] - n + 2 - A[1], A[n - 2] - A[0] - n + 2);
        for (int j = 0; j < n; ++j) {
            while (A[j] - A[i] >= n) ++i;
            if (j - i + 1 == n - 1 && A[j] - A[i] == n - 2)
                low = min(low, 2);
            else
                low = min(low, n - (j - i + 1));
        }
        return {low, high};
    }
};
int main()
{}
