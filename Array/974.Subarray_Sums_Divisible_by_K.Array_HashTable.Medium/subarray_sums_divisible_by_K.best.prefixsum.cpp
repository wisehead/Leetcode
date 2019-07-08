/*******************************************************************************
 *      file name: subarray_sums_divisible_by_K.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/07-18:01:54                              
 *  modified time: 2019/07/07-18:01:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
About the problems - sum of contiguous subarray , prefix sum is a common technique.
Another thing is if sum[0, i] % K == sum[0, j] % K, sum[i + 1, j] is divisible by by K.
So for current index j, we need to find out how many index i (i < j) exit that has the same mod of K.
Now it easy to come up with HashMap <mod, frequency>

Time Complexity: O(N)
Space Complexity: O(K)
 */
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : A) {
            prefix = (prefix + a % K + K) % K;
            res += count[prefix]++;
        }
        return res;
    }
};
int main()
{}
