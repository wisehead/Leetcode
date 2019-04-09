/*******************************************************************************
 *      file name: minumum_size_subarray_sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/09-10:18:00                              
 *  modified time: 2019/04/09-10:18:00                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		vector<int> vec(nums);
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if (vec[i] >= s) return 1;
		}
		for (int i = 1; i < size; i++)
		{
			for (int j = size - 1; j >= i; j--)
			{
				vec[j] = vec[j] + nums[j-i];
                //cout<<"i:"<<i<<"    j:"<<j<<"vec[j]"<<vec[j]<<endl;
				if (vec[j] >= s) return i+1;
			}
		}
		return 0;
    }
};
int main()
{}
