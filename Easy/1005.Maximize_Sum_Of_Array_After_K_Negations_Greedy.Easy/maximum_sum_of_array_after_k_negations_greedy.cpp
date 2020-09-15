/*******************************************************************************
 *      file name: maximum_sum_of_array_after_k_negations_greedy.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/15-15:00:46                              
 *  modified time: 2020/09/15-15:00:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int sum = 0;
		int x = 0;
		for (int i = 0; i < A.size(); i++) {
			if (K > 0) {
				if (A[i] < 0) {
					A[i] = -A[i];
					K--;
				} else if (A[i] == 0) {
					K = 0;
				} else if (K % 2 == 0) {
					K = 0;
				}
				else {
					if (i-1 >= 0) {
						x = min(A[i-1], A[i]);
						K = 0;
					} else {
						x = A[i];
						K = 0;
					}
				}
			}
			sum += A[i];
		}
		sum -= 2*x; 
		return sum;
    }
};
int main()
{}
