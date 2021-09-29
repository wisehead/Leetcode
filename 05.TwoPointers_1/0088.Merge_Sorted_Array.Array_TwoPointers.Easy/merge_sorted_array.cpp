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
		int count_1 = 0, count_2 = 0;
		vector<int>::iterator it1, it2;
		it1 = nums1.begin();
		it2 = nums2.begin();
		//print_vec(nums1);
		//print_vec(nums2);
		while (it1 != nums1.end() && it2 != nums2.end() && count_1 < m && count_2 < n)
		{
			//cout<<" it1 is:"<<*it1;
			//cout<<"; it2 is:"<<*it2<<endl;
			if (*it1 <= *it2)
			{
				it1++;
				count_1++;
			}
			else
			{
				it1 = nums1.insert(it1, *it2);
				it1++;
				it2++;
				count_2++;
			}
			//print_vec(nums1);
		}

		//cout<<"haha: count_1 + count_2:"<<count_1 + count_2<<endl;
		while (count_2 < n && it2 != nums2.end())
		{
			//cout<<"count_1 + count_2:"<<count_1 + count_2<<endl;
			nums1[count_1 + count_2] = *it2;
			count_2++;
			it2++;
		}
		nums1.resize(m+n);
		//print_vec(nums1);
    }
};
int main()
{
	Solution sol;
	int array_1[5] = {1,1,2,3,3};
	int array_2[5] = {2,3,3,7,8};
	vector<int> vec1(array_1, array_1+5);
	vec1.resize(10);
	vector<int> vec2(array_2, array_2+5);
	sol.merge(vec1, 5, vec2, 5);
	vector<int> vec3(array_1, array_1+1);
	vec3.resize(6);
	sol.merge(vec3, 0, vec2, 5);
	vector<int> vec4(array_2, array_2+1);
	vec4.resize(2);
	vector<int> vec5(array_1, array_1+1);
	sol.merge(vec4, 1, vec5, 1);
	int array_3[6] = {4,0,0,0,0,0};
	int array_4[5] = {1,2,3,5,6};
	vector<int> vec7(array_3, array_3+6);
	vector<int> vec8(array_4, array_4+5);
	sol.merge(vec7, 1, vec8, 5);
}

