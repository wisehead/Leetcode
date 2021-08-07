/*******************************************************************************
 *      file name: search_insert_pos.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/24-10:10                                    
 * modified time: 17/10/24-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {  
public:  
    int searchInsert(vector<int>& nums, int target) {  
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
		int len = nums.size();
		int low  = 0;
		int high = len - 1;
		int mid = 0;
		int flag = 1;
		if (len == 0)
			return 0;
		if (target <= nums[0])
			return 0;
		if (target == nums[len - 1])
			return len-1;
		if (target > nums[len - 1])
			return len;
		while (low < high)
		{
			mid = (low + high)/2;
			if (target == nums[mid])
			{
				return mid;
			}
			else if(target < nums[mid]) 
			{
				if (high == mid)
				{
					break;
				}
				else
					high = mid;
			}
			else
			{
				if (low == mid)
					break;
				else
					low = mid;
			}
		}

		return mid+1;
		
		/*
		vector<int>::iterater it;
		for (it = nums.begin(); it != nums.end(); it++)
		{
		}
		*/
    }  
};  

int main()
{
	Solution sol;
	int arr[6] = {1,3,5,7,9,11};  
	vector<int> vec(arr, arr+6); 
	vector<int> vec0; 
	vector<int> vec1(arr, arr+1); 
	int ret = -1;
	ret = sol.searchInsert(vec, 0);
	cout<<"0: ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec, 1);
	cout<<"1:vret is: "<<ret<<endl;
	ret = sol.searchInsert(vec, 2);
	cout<<"2: ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec, 3);
	cout<<"3: ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec, 10);
	cout<<"10: ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec, 11);
	cout<<"11: ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec, 12);
	cout<<"12: ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec, 13);
	cout<<"13: ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec1, 0);
	cout<<"0: vec1 ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec1, 1);
	cout<<"1: vec1 ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec1, 2);
	cout<<"2: vec1 ret is: "<<ret<<endl;
	ret = sol.searchInsert(vec0, 0);
	cout<<"0: vec0 ret is: "<<ret<<endl;
}
