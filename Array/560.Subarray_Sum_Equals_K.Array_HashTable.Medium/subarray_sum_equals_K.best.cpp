/*******************************************************************************
 *      file name: subarray_sum_equals_K.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/24-22:49:52                              
 *  modified time: 2019/04/24-22:49:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum=0; // cumulated sum
        map<int,int> rec; // prefix sum recorder
        int cnt = 0; // number of found subarray
        rec[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};
int main()
{}
