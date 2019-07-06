/*******************************************************************************
 *      file name: maximum_width_ramp.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/06-22:44:21                              
 *  modified time: 2019/07/06-22:44:21                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Solution 1
Intuition:
Keep a decraesing stack.
For each number,
binary search the first smaller number in the stack.

When the number is smaller the the last,
push it into the stack.

Time Complexity:
O(NlogN)

Solution 2
Improve the idea above.
Still one pass and keep a decraesing stack.

Time Complexity:
O(N)
 */
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            if (s.empty() || A[s.top()] > A[i])
                s.push(i);
        for (int i = n - 1; i > res; --i)
            while (!s.empty() && A[s.top()] <= A[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }
};
int main()
{}
