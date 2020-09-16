/*******************************************************************************
 *      file name: next_permutation.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/27-10:13:26                              
 *  modified time: 2019/02/27-10:13:26                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int size = nums.size();
        if (size <= 1)return;
		int i = 0;
		for (i = size - 1; i > 0; i--) 
		{
			if (nums[i] > nums[i-1]) break;
		}
        if (i > 0)
        {
		    for (int j = size - 1; j >= i; j--)
		    {
		    	if (nums[j] > nums[i-1])
		    	{
		    		swap(nums[i-1], nums[j]);
			    	break;
		    	}
		    }
        }
		reverse(nums.begin() + i, nums.end());
    }
};
int main()
{
	Solution sol;
	int array[4] = {1,3,4,2};
	vector<int> vec(array, array+4);
	sol.nextPermutation(vec);
	for (int i = 0; i < vec.size(); i++)
		cout<<"vec["<<i<<"]"<<vec[i]<<"	";
	cout<<endl;
}
