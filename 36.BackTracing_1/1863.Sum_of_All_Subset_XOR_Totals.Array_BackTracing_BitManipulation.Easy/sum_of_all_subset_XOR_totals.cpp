/*******************************************************************************
 *      file name: sum_of_all_subset_XOR_totals.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/06-09:22:45                              
 *  modified time: 2021/08/06-09:22:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> helper(vector<int>& nums, int N) {
        vector<int> res;
        
        if (N == 0) {
            res.push_back(0);
            return res;
        }

        vector<int> vec = helper(nums, N-1);
        res.insert(res.end(), vec.begin(), vec.end());
        
        int x = nums[N-1];
        for (auto e : vec) {
            res.push_back(x^e);
        }
        
        return res;
    }    
    int subsetXORSum(vector<int>& nums) {
        vector<int> vec = helper(nums, nums.size());
        int sum = 0;
        for (auto e : vec) sum += e;
        return sum;
    }
};
int main()
{}
