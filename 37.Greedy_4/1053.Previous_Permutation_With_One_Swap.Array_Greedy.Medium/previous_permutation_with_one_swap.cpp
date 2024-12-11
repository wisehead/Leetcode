/*******************************************************************************
 *      file name: previous_permutation_with_one_swap.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/18-12:56:45                              
 *  modified time: 2020/01/18-12:56:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
		int n = A.size();
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (A[j] <= A[i])
					break;
				if (A[j] > A[i])
				{
					int tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
					return A;
				}
			}
		}
		return A;
    }
};
int main()
{}
