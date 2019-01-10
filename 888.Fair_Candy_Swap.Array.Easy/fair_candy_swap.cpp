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
		delta = (sum_A - sum_B)/2;
		for (int i=0; i<A.size(); i++)
		{
			vector<int>::iterator it = find(B.begin(), B.end(), A[i] - delta);
			if (it != B.end())
			{
				res.push_back(A[i]);
				res.push_back(A[i] - delta);
				break;
			}
		}
		return res;
    }
};
int main()
{}
