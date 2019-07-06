/*******************************************************************************
 *      file name: maximum_width_ramp.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/06-22:44:21                              
 *  modified time: 2019/07/06-22:44:21                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
		int n = A.size();
		vector<int> maxv(n, 0);
		int top = A[n-1];
		int max_width = 0;
		for (int i = n - 1; i>= 0; i--)
		{
			if (A[i] > top)
				top = A[i];
			maxv[i] = top;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int pos = upper_bound(maxv.begin()+i+1, maxv.end(), A[i], greater<int>()) - maxv.begin();
			int delta = pos - 1 - i;
			if (delta > max_width)
				max_width = delta;
		}
		return max_width;

    }
};
int main()
{}
