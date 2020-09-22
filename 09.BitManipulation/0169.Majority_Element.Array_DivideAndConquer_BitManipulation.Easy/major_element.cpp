/*******************************************************************************
 *      file name: major_element.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/29-11:11                                    
 *  modified time: 17/11/29-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		vector<int>::iterator it;
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
			if (zero_count > one_count)
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
			one_count = 0;
			zero_count = 0;
		}
		return nums[0];
    }
};
int main()
{
	Solution sol;
	int array[] = {1,2,3,4,2,2,2};
	vector<int> vec(array, array+7);
	int out = sol.majorityElement(vec);
	cout<<"the majority num is:"<<out<<endl;
}
