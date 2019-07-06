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
		int max_width = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = n -1; j > i; j--)
			{
				if (A[j] >= A[i])
				{
					if (j - i > max_width)
						max_width = j - i;
					break;
				}
			}
		}
		return max_width;
		/*
		vector<int> maxv(n, 0);
		int top = A[n-1];
		int max_width = 0;
		for (int i = n - 1; i>= 0; i--)
		{
			if (A[i] > top)
				top = A[i];
			maxv[i] = top;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				if (maxv[j] >= A[i])
					continue;
				break;
			}
		}
		*/

    }
};
int main()
{}
