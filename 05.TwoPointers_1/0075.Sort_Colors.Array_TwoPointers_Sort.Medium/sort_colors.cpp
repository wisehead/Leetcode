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
		int size = nums.size();
		int pos_0 = 0, pos_2 = size - 1;
        
        if (size == 1)
            return;
        
		for (int i =  0 ; (i <= pos_2) && (pos_0 <= pos_2); )
		{
			if (nums[i] == 0 )
			{
    			while ((pos_0 <= pos_2) && (!nums[pos_0]) ) pos_0++;
                if (i < pos_0) 
                {
                    i = pos_0;
                    continue;
                }
				swap(nums[pos_0], nums[i]);
			}
			else if (nums[i] == 2)
			{
				while ((pos_0 <= pos_2) && (nums[pos_2] == 2)) pos_2--;
                if (i > pos_2) 
                {
                    i = pos_2;
                    continue;
                }
				swap(nums[pos_2], nums[i]);
			}
            else
                i++;
		}
    }
};
int main()
{}
