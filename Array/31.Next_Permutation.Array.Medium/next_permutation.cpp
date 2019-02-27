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
	void printvec(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
			cout<<"nums["<<i<<"]"<<nums[i]<<"	";
		cout<<endl;
	}

    void nextPermutation(vector<int>& nums) {
		printvec(nums);
		int size = nums.size();
        if (size <= 1)return;
		int i = 0;
		for (i = size - 1; i > 0; i--) 
		{
			if (nums[i] > nums[i-1]) break;
		}
        //if (i==0)return;
		cout<<"i:"<<i<<endl;
		//swap(nums[i-1], nums[size-1]);
		//printvec(nums);
        if (i > 0)
        {
		    for (int j = size - 1; j >= i; j--)
		    {
		    	cout<<"nums["<<j<<"]"<<nums[j]<<"	";
		    	if (nums[j] > nums[i-1])
		    	{
			    	cout<<"exchange"<<endl;
		    		swap(nums[i-1], nums[j]);
			    	break;
		    	}
		    }
		    cout<<endl;
        }
		printvec(nums);
		reverse(nums.begin() + i, nums.end());
		printvec(nums);
    }
};
int main()
{
	Solution sol;
	int array[4] = {1,3,4,2};
	vector<int> vec(array, array+4);
	sol.nextPermutation(vec);
}
