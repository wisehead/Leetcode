/*******************************************************************************
 *      file name: sum_of_subarray_minimums.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/22-09:54:20                              
 *  modified time: 2019/06/22-09:54:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Intuition:
I guess this is a general intuition for most solution.
res = sum(A[i] * f(i))
where f(i) is the number of subarrays,
in which A[i] is the minimum.

To get f(i), we need to find out:
left[i], the length of strict bigger numbers on the left of A[i],
right[i], the length of bigger numbers on the right of A[i].

Then,
left[i] + 1 equals to
the number of subarray ending with A[i],
and A[i] is single minimum.

right[i] + 1 equals to
the number of subarray starting with A[i],
and A[i] is the first minimum.

Finally f(i) = (left[i] + 1) * (right[i] + 1)

For [3,1,2,4] as example:
left + 1 = [1,2,1,1]
right + 1 = [1,3,2,1]
f = [1,6,2,1]
res = 3 * 1 + 1 * 6 + 2 * 2 + 4 * 1 = 17

Explanation:
To calculate left[i] and right[i],
we use two increasing stacks.

It will be easy if you can refer to this problem and my post:
901. Online Stock Span
I copy some of my codes from this solution.

More:
For some more similar problem, I suggest
828. Unique Letter String
891. Sum of Subsequence Widths

Complexity:
All elements will be pushed twice and popped at most twice
O(N) time, O(N) space
 */
class Solution {
public:
    int sumSubarrayMins(vector<int> A) {
        int res = 0, n = A.size(), mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1,s2;
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > A[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({A[i], count});
            left[i] = count;
        }
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= A[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({A[i], count});
            right[i] = count;
        }
        for (int i = 0; i < n; ++i)
            res = (res + A[i] * left[i] * right[i]) % mod;
        return res;
    }
};
int main()
{}
