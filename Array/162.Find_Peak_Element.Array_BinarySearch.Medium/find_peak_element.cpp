/*******************************************************************************
 *      file name: find_peak_element.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/08-09:41:49                              
 *  modified time: 2019/04/08-09:41:49                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), INT_MIN);
		nums.push_back(INT_MIN);
		int left = 1, right = n;
		int mid = 0;
        if (n > 0 && nums[1] == INT_MIN) 
        {
            if (n == 1) return 0;
            left++;
        }
		while (left <= right)
		{
			mid = (left + right)/2;
			if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
				return mid - 1;
			
            if (nums[left+1] < nums[left]) return left-1;
			if (nums[right-1] < nums[right]) return right-1;
            
			if(nums[mid] < nums[left])
				right = mid;
			else if(nums[mid] < nums[right])
				left = mid;
			else
			{
				left++;
				right--;
			}

		}
		return -1;
    }
};
int main()
{}
