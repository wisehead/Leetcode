/*******************************************************************************
 *      file name: k_diff_pairs_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/22-11:08:03                              
 *  modified time: 2018/08/22-11:08:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
		sort(nums.begin(), nums.end());
		int count = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int j = i+1;
			while (j < nums.size() && nums[i] + k >= nums[j])
			{
				if (nums[j] == nums[i])
                {
                    if (k==0)
                    {
                        count++;
                        while (nums[j] == nums[i])
                            i++;
                        i--;
                    }
					break;
                }
				//cout<<"i:"<<i<<"	j:"<<j<<endl;
				if (nums[i] + k == nums[j])
				{
					count++;
					break;
				}
				//cout<<"count:"<<count<<endl;
				j++;
			}
		}
		return count;
    }
};
int main()
{
	int arr[5] = {3,1,4,1,5};
	vector<int> input(arr, arr+5);
	int k = 2;
	int ret = 0;
	Solution sol;
	ret = sol.findPairs(input, k);
	cout<<"ret:"<<ret<<endl;
}
