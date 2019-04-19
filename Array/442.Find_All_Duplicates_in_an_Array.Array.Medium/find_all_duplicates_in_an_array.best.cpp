/*******************************************************************************
 *      file name: find_all_duplicates_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/19-09:34:15                              
 *  modified time: 2019/04/19-09:34:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) res.push_back(nums[i]);
        }
        return res;
    }
};
int main()
{}
