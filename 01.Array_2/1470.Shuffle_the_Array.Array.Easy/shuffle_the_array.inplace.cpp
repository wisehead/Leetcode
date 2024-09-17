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
        for (int i = N-1; i >= N/2; i--) {
            nums.insert(nums.begin()+i+1-N/2, nums[N-1]);
            nums.erase(nums.begin()+N);
        }
        return nums;
    }
};
int main()
{}
