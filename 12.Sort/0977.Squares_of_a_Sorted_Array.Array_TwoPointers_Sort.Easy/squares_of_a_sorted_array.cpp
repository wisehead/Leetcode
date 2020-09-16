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
		for (int i = 0; i < size; i++) A[i] *= A[i];
		sort(A.begin(), A.end());
		return A;
    }
};
int main()
{}
