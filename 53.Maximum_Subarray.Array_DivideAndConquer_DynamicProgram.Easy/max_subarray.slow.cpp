/*******************************************************************************
 *      file name: max_subarray.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/28-10:10                                    
 * modified time: 17/10/28-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
void dump(vector<int>& myVector)  
{  
    vector<int>::iterator it = myVector.begin();  
    cout << "[";   
    for (; it != myVector.end(); ++it)  
        cout << *(it) << ", ";   
    cout << "]";   
}  

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int max = 0;
		int r_step = 0, r_start = 0, start = 0;
		int len = nums.size();
		if (len > 0)
			max = nums[0];
		vector<int> vec(len);
		for (int step = 0; step < len; step++)
		{
			//cout<<"step is:"<<step<<endl;
			for (int i=start; i<len-step; i++)
			{
				vec[i] += nums[i+step];
				if (vec[i] > max)
				{
					max = vec[i];
					r_step = step;
					r_start = i;
				}
				//cout<<"vec["<<i<<"]"<<vec[i]<<" ";
			}
			//cout<<endl;
			for (int i=start; i<len-step; i++)
			{
				start = i;
				if (vec[i] > 0)
					break;
			}
		}
		cout<<"max is: "<<max<<" r_start is:"<<r_start<<" r_step is:"<<r_step<<endl;
		return max;
    }
};

int main()
{
	Solution sol;
	int array[9] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(array, array+9);
	sol.maxSubArray(nums);
	vector<int> nums0;
	vector<int> nums1(array, array+1);
	vector<int> nums2(array, array+2);
	vector<int> nums3(array, array+3);
	vector<int> nums4(array, array+4);
	vector<int> nums5(array, array+5);
	vector<int> nums6(array, array+6);
	vector<int> nums7(array, array+7);
	vector<int> nums8(array, array+8);
	sol.maxSubArray(nums0);
	sol.maxSubArray(nums1);
	sol.maxSubArray(nums2);
	sol.maxSubArray(nums3);
	sol.maxSubArray(nums4);
	sol.maxSubArray(nums5);
	sol.maxSubArray(nums6);
	sol.maxSubArray(nums7);
	sol.maxSubArray(nums8);
}
