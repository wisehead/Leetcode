/*******************************************************************************
 *      file name: merge_sorted_array.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/05-11:11                                    
 * modified time: 17/11/05-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void print_vec(vector<int>& nums)
	{
		vector<int>::iterator it;
		for (it = nums.begin(); it < nums.end(); it++)
		{
			cout<<" "<<*it;
		}
		cout<<endl;
	}

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i1 = 0, i2 = 0;
		int min = (m > n) ? n : m;
		print_vec(nums1);
		print_vec(nums2);
		while (i1 < m && i2 < n)
		{
			if (nums1[i1] <= nums2[i2])
			{
				i1++;
			}
			else
			{
				nums1.insert(i1, nums2[i2]);
				i2++;
			}
		}
		if (i2 < n)
		{
			nums1.insert(i1, i2, n-1);
		}
		print_vec(nums1);
    }
};
int main()
{
	Solution sol;
	int array_1[5] = {1,1,2,3,3};
	int array_2[5] = {2,3,3,7,8};
	vector<int> vec1(array_1, array_1+5);
	vector<int> vec2(array_2, array_2+5);
	sol.merge(vec1, 5, vec2, 5);
}

