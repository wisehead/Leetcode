/*******************************************************************************
 *      file name: 3rd_max_num.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/02/25- 2:02                                    
 *  modified time: 18/02/25- 2:02                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
#define MIN_VAL (-2147483648)
class Solution {
public:
    int getMax(vector<int>& nums) {
		vector<int>::iterator it;
		int max = MIN_VAL;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			if (*it > max)
				max = *it;
		}
		for (it = nums.begin(); it != nums.end(); )
		{
			if (*it == max)
			{
				nums.erase(it);
			}
			else
			{
				it++;
			}
		}
		return max;
    }

    int thirdMax(vector<int>& nums) {
		if (nums.size() < 3)
		{
			return getMax(nums); 
		}
		int max = MIN_VAL;
		int real_max = MIN_VAL;
		for (int i = 0; i < 3; i++)
		{
			max = getMax(nums);
			if (i == 0)
				real_max = max;
			if (nums.size() == 0 && i != 2)
				return real_max;
		}
		return max;
    }
};
int main()
{
	int arr1[3] = {3, 2, 1}; 
	vector<int> vec1(arr1, arr1 + 3);
	int arr2[4] = {2, 2, 3, 1}; 
	vector<int> vec2(arr2, arr2 + 4);
	int arr3[2] = {1, 2}; 
	vector<int> vec3(arr3, arr3 + 2);
	int arr4[3] = {1, 1, 2}; 
	vector<int> vec4(arr4, arr4 + 3);
	Solution sol;
	int third_max = MIN_VAL;
	third_max = sol.thirdMax(vec4); 
	cout<<"3rd max val is:"<<third_max<<endl;
}
