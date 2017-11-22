/*******************************************************************************
 *      file name: single_num.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/22-11:11                                    
 * modified time: 17/11/22-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		vector<int>::iterator it;
		int size = nums.size();
		if (size == 0)
			return 0;
		int one_count = 0;
		int zero_count = 0;

		int mask = 0;
		for (int i=0; i<32; i++)
		{
			mask = 1<<i;
			cout<<"mask for "<<i<<" is:"<<mask<<endl;
			for (it = nums.begin(); it != nums.end(); it++)
			{
				if ((*it & mask) != 0)
				{
					one_count++;
				}
				else 
				{
					zero_count++;
				}
			}
			cout<<"one_count is:"<<one_count<<endl;
			cout<<"zero_count is:"<<zero_count<<endl;
			if (one_count % 2 ==0)
			{
				for (it = nums.begin(); it != nums.end(); )
				{
					if ((*it & mask) != 0)
						nums.erase(it);
					else 
						it++;
				}
			}
			else
			{
				for (it = nums.begin(); it != nums.end(); )
				{
					if ((*it & mask) == 0)
						nums.erase(it);
					else 
						it++;
				}
			}
			if (nums.size() == 1)
				break;
			one_count = 0;
			zero_count = 0;
		}
		return nums[0];
    }
};
int main()
{
	Solution sol;
	//int arr[5] = {-1, -2, 3, -2, -1}; 
	int arr[] = {17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6}; 
	vector<int> vec(arr, arr+21);
	int ret = 0;
	ret = sol.singleNumber(vec);
	cout<<"output is:"<<ret<<endl;
}
