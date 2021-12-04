/*******************************************************************************
 *      file name: minumum_size_subarray_sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/09-10:18:00                              
 *  modified time: 2019/04/09-10:18:00                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
The O(n) solution is to use two pointers: l and r. First we move r until we get a sum >= s, 
then we move l to the right until sum < s. In this process, store the minimum length between l and r. 
Since each element in nums will be visited by l and r for at most once. This algorithm is of O(n) time.
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
};
int main()
{}
