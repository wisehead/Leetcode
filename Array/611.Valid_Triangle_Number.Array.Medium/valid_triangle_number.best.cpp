/*******************************************************************************
 *      file name: valid_triangle_number.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/26-17:58:14                              
 *  modified time: 2019/04/26-17:58:14                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 0, n = nums.size();
		for (int i=n-1;i>=2;i--) {
			int l = 0, r = i-1;
			while (l < r) {
				if (nums[l] + nums[r] > nums[i]) {
					count += r-l;
					r--;
				}
				else l++;
			}
		}
		return count;
    }
};
int main()
{}
