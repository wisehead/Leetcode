/*******************************************************************************
 *      file name: binary_prefix_divisible_by_5.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/14-19:14:34                              
 *  modified time: 2019/07/14-19:14:34                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
		int n = A.size();
		vector<bool> vec(n, false);
		int base = 0;
		for (int i = 0; i < n; i++)
		{
			base = base*2 + A[i];
			base = base % 5;
			if (base % 5 == 0)
				vec[i] = true;
		}
		return vec;
    }
};
int main()
{}
