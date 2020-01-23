/*******************************************************************************
 *      file name: largest_number_at_least_twice_of_others.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/05-10:59:31                              
 *  modified time: 2018/10/05-10:59:31                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxn = INT_MIN, idx = -1, sec = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxn) {
                sec = maxn;
                maxn = nums[i];
                idx = i;
            } else if(nums[i] > sec){
                sec = nums[i];
            }
        }
        return sec * 2 > maxn ? -1 : idx;
    }
};
int main()
{}
