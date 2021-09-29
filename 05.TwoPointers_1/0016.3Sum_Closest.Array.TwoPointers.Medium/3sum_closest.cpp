/*******************************************************************************
 *      file name: 3sum_closest.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/25-10:14:09                              
 *  modified time: 2019/02/25-10:14:09                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		int min_diff =  INT_MAX;
		int min_sum =  0;
        int x = 0, y = 0, z = 0;
		for (int i = 0; i < nums.size(); i++) {
			int t = target - nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			while (front < back) {
				int sum = nums[front] + nums[back];
				// Finding answer which start from number num[i]
				int diff = abs(sum - t);
				if (diff < min_diff) 
				{
					min_diff = diff;
					min_sum = sum + nums[i];
                    x = nums[i]; y = nums[front]; z = nums[back];
				}
				if (sum < t)
					front++;
				else if (sum > t)
					back--;
				else {
					return sum + nums[i];
				}
			}
		}
        cout<<"min_sum:"<<min_sum<<"    min_diff:"<<min_diff<<" x:"<<x<<"   y:"<<y<<"   z:"<<z<<endl;
		return min_sum;
    }
};
int main()
{}
