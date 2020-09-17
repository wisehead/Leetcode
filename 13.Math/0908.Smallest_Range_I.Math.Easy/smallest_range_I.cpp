/*******************************************************************************
 *      file name: smallest_range_I.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/18-19:02:25                              
 *  modified time: 2019/01/18-19:02:25                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
		int size = A.size();
		int min_v = A[0], max_v = A[0]; 
		for (int i=0; i<size; i++)
		{
			int temp = A[i];
			min_v = min(min_v, temp);
			max_v = max(max_v, temp);
		}
		int ret = max_v - min_v - 2*K;
		if (ret < 0) ret = 0;
		return ret;
    }
};
int main()
{}
