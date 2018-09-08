/*******************************************************************************
 *      file name: non_decreasing_array.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/08-23:09:45                              
 *  modified time: 2018/09/08-23:09:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return true;
		int count = 0;
        int pos = 0;
		for (int i=0; i<len-1;i++)
		{
			if (nums[i] > nums[i+1])
            {
				count++;
                pos = i;
            }
			if (count > 1)
				return false;
		}
        
        //if (pos > 0 && nums[pos-1] > nums[pos+1]) return false;
        if (pos != 0 && pos != len-2)
        {
            if (nums[pos-1] <= nums[pos+1] || nums[pos] <= nums[pos+2]) return true;
            else return false;
        }
		return true;
    }
};
int main()
{}
