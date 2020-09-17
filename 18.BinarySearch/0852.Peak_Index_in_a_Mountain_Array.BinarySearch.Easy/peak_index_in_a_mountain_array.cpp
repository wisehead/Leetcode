/*******************************************************************************
 *      file name: peak_index_in_a_mountain_array.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/19-15:18:58                              
 *  modified time: 2018/12/19-15:18:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
		int size = A.size();
		int start = 0;
		int end = size - 1;
		int mid = 0;
		while ( start < end)
		{
			mid = (start + end)/2;
			if (A[mid+1] < A[mid] && A[mid-1] < A[mid])
			{
				return mid;
			}
			if (A[mid+1] > A[mid] && A[mid-1] < A[mid])
			{
				start = mid + 1;
			}
			else if (A[mid+1] < A[mid] && A[mid-1] > A[mid])
			{
				end = mid;
			}
		}
		return start;
    }
};
int main()
{}
