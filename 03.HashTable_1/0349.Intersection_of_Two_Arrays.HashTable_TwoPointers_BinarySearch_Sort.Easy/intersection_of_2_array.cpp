/*******************************************************************************
 *      file name: intersection_of_2_array.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/06- 1:01                                    
 *  modified time: 18/01/06- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1;
		set<int> s2;
		vector<int> vec;
		set<int>::iterator it_s1;
		set<int>::iterator it_s2;
		vector<int>::iterator it;
		for (it = nums1.begin(); it != nums1.end(); it++)
		{
			it_s1 = s1.find(*it);
			if (it_s1 == s1.end())
				s1.insert(*it);
		}
		for (it = nums2.begin(); it != nums2.end(); it++)
		{
			it_s2 = s2.find(*it);
			if (it_s2 == s2.end())
			{
				s2.insert(*it);
				it_s1 = s1.find(*it);
				if (it_s1 != s1.end())
					vec.push_back(*it);
			}
		}
		return vec;
    }
};
int main()
{
	int array1[] = {1, 2, 2, 1};
	int array2[] = {2, 2};
	vector<int> nums1(array1, array1+4);
	vector<int> nums2(array2, array2+2);
	Solution sol;
	vector<int> vec;
	vec = sol.intersection(nums1, nums2);
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout<<" "<<*it;
	}
	cout<<endl;
}
