/*******************************************************************************
 *      file name: add_to_array_form_of_integer.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/20-09:31:53                              
 *  modified time: 2019/02/20-09:31:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
		long long sum_A = 0;
		long long base = 1;
		vector<int> res;
		reverse(A.begin(), A.end());
		for (auto &e : A)
		{
			sum_A +=  e*base;
			base *= 10;
		}
		long long result = sum_A + K;
		while (result > 0)
		{
			int mod = result % 10;
			res.push_back(mod);
			result /= 10;
		}
        reverse(res.begin(), res.end());
		return res;
    }
};
int main()
{}
