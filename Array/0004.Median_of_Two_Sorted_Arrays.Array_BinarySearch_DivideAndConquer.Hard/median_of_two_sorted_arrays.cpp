/*******************************************************************************
 *      file name: median_of_two_sorted_arrays.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/22-14:41:21                              
 *  modified time: 2020/01/22-14:41:21                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
	bool is_int(double x) {
		return (floor(x) == ceil(x));
	}

	double get_val(vector<int>& vec, double x)
	{
		double v;
		if (is_int(x))
			v =  vec[floor(x)];
		else
			v = (vec[floor(x)] + vec[ceil(x)])/2;
		return v;
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int target = (n1+n2)/2;
		double l1 = 0, h1 = n1 - 1, m1 = (l1 + h1)/2;
		double l2 = 0, h2 = n2 - 1, m2 = (l2 + h2)/2;
		double v1, v2;
		while (floor(m1) + floor(m2) != target)
		{
			v1 = get_val(nums1, m1);
			v2 = get_val(nums2, m2);
			if (v1 == v2) break;
			if (v1 < v2)
			{
				if (h1 - ceil(m1) <= floor(m2) - l2)
				{
					l1 = floor(m1);
					m1 = (l1 + h1)/2;
					int delta = floor(m1) - floor(l1);
					m2 -= delta; 
					h2 -= delta;
				}
				else//h1 - ceil(m1) > floor(m2) - l2
				{
					h2 = ceil(m2);
					m2 = (l2 + h2)/2;
					int delta = ceil(h2) - ceil(m2);
					m1 += delta;
					l1 += delta;
				}
			}
			else//v1 > v2
			{
				if (h2 - ceil(m2) <= floor(m1) - l1)
				{
					l2 = floor(m2);
					m2 = (l2 + h2)/2;
					int delta = floor(m2) - floor(l2);
					m1 -= delta; 
					h1 -= delta;
				}
				else//h1 - ceil(m1) > floor(m2) - l2
				{
					h1 = ceil(m1);
					m1 = (l1 + h1)/2;
					int delta = ceil(h1) - ceil(m1);
					m2 += delta;
					l2 += delta;
				}
			}
		}
        cout<<"m1:"<<m1<<"  m2:"<<m2<<endl;
		if (is_int(m1)) return nums1[m1];
        if (is_int(m2)) return nums2[m2];
        return max(nums1[floor(m1)], nums2[floor(m2)]) + 1;
    }
};
int main()
{}
