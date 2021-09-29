/*******************************************************************************
 *      file name: sort_colors.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/22-09:28:49                              
 *  modified time: 2019/03/22-09:28:49                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0;
        int j = 0; 
        int k = nums.size()-1;
        
        while (j <= k)
        {
            auto num = nums[j];
            
            if (num==0) 
                std::swap(nums[i++],nums[j++]);
            else if (num==1)
                j++;
            else
                std::swap(nums[j],nums[k--]);
        }
    }
};
int main()
{}
