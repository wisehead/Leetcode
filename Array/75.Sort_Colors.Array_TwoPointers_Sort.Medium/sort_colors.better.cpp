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
        int i = 0, start = 0, end = nums.size() - 1;
        while (i <= end && start <= end)
        {
            switch (nums[i]) 
            {
                case 0: 
                    while ((start <= end) && (!nums[start]) ) start++;
                    if (i < start) 
                    {
                        i = start;
                        continue;
                    }
                    swap(nums[start], nums[i]);
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    while ((start <= end) && (nums[end] == 2)) end--;
                    if (i > end) 
                    {
                        i = end;
                        continue;
                    }
                    swap(nums[end], nums[i]);
                    break;
            }
        }
    }
};
int main()
{}
