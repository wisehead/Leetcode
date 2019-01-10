/*******************************************************************************
 *      file name: fair_candy_swap.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/10-22:30:44                              
 *  modified time: 2019/01/10-22:30:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		vector<int> res;
		int sum_A = 0, sum_B = 0;
		for (int i=0; i<A.size(); i++)
		{
			sum_A += A[i];
		}
		for (int i=0; i<B.size(); i++)
		{
			sum_B += B[i];
		}
		//int ave = (sum_A + sum_B)/2;
		int delta = 0;
		vector<int> vec_small, vec_big;
		if (sum_A > sum_B)
		{
			vec_small = B;
			vec_big = A;
			delta = (sum_A - sum_B)/2;
		}
		else
		{
			vec_small = A;
			vec_big = B;
			delta = (sum_B - sum_A)/2;
		}
		for (int i=0; i<vec_small.size(); i++)
		{
			vector<int>::iterator it = find( vec_big.begin(), vec_big.end(), vec_small[i] + delta);
			if (it != vec_big.end())
			{
				res.push_back(vec_small[i]);
				res.push_back(vec_small[i] + delta);
			}
		}
		return res;
    }
};
int main()
{}
