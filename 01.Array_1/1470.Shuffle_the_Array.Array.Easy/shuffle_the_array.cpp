/*******************************************************************************
 *      file name: shuffle_the_array.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/21-09:55:47                              
 *  modified time: 2021/11/21-09:55:47                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int N = nums.size();
        vector<int> vec;
        for (int i = 0; i < N/2; i++) {
            vec.push_back(nums[i]);
            vec.push_back(nums[i+N/2]);
        }
        return vec;
    }
};
int main()
{}
