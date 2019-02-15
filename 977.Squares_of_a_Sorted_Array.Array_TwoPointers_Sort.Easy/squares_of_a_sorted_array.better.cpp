/*******************************************************************************
 *      file name: squares_of_a_sorted_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/15-09:46:37                              
 *  modified time: 2019/02/15-09:46:37                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
		int size = A.size();
		vector<int> res(A);
		int pos = size - 1;
		for (int i = 0, j = size - 1; i <= j; ) 
		{
			if (abs(A[i]) > abs(A[j]))
			{
				res[pos--] = A[i]*A[i];
				i++;
			}
			else
			{
				res[pos--] = A[j]*A[j];
				j--;
			}
		}
		return res;
    }
};
int main()
{}
