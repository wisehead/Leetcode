/*******************************************************************************
 *      file name: longest_turbulent_subarray.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/08-09:59:09                              
 *  modified time: 2019/07/08-09:59:09                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
We use the counter (cnt) to track subarray size. Our counter is positive if we expect '>', and '<' otherwise. Obviously, for each turn we flip the sign.

If the comparison matches the counter sign (e.g. A[i] > A[i + 1] and cnt > 0 ), we increment (or decrement the negative) counter. Otherwise, we reset the counter to 1 (or -1). One edge case here is when two numbers are equal. We set the counter to zero in this case.
 */
class Solution {
public:
	int maxTurbulenceSize(vector<int>& A, int res = 0) {
	  for (auto i = 0, cnt = 0; i + 1 < A.size(); ++i, cnt *= -1) {
	    if (A[i] > A[i + 1]) cnt = cnt > 0 ? cnt + 1 : 1;
	    else if (A[i] < A[i + 1])  cnt = cnt < 0 ? cnt - 1 : -1;
	    else cnt = 0;
	    res = max(res, abs(cnt));
	  }
	  return res + 1;
	}
};
int main()
{}
