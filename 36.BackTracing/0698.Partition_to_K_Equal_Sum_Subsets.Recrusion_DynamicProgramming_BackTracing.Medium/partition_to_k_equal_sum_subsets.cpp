/*******************************************************************************
 *      file name: partition_to_k_equal_sum_subsets.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-11:08:00                              
 *  modified time: 2020/10/29-11:08:00                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto e : nums) sum += e;
        if (sum % k != 0) return false;
        int avg = sum / k;
        vector<bool> visit(k,false);
        return dfs(visit, nums,0, 0, avg, k);
    }
    
    bool dfs(vector<bool>& visit, vector<int>& nums, int current, int start, int avg, int k) {
        if (k == 0) {
            return true;
        }        
        int size = nums.size();
        if (current == avg) {
            return dfs(visit, nums, 0, 0, avg, k-1);
        }
            
        for (int i = start; i < size; i++) {
            if (!visit[i] && current + nums[i] <= avg) {
                visit[i] = true;
                if (dfs(visit, nums, current+ nums[i], i+1, avg, k)) return true;
                visit[i] = false;
            }
        }
        return false;
    }
    
};
int main()
{}
