/*******************************************************************************
 *      file name: best_sightseeing_pair.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/14-17:37:01                              
 *  modified time: 2019/07/14-17:37:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
		int n = A.size();
		vector<int> vec(n, 0);
		int max_j = INT_MIN, max1 = INT_MIN;
		for (int i = n-1; i >= 0; i--)
		{
			max_j = max(A[i] - i, max_j);
			vec[i] = max_j;
		}
		for (int i = 0; i < n - 1; i++)
			max1 = max(A[i]+i + vec[i+1], max1);
		return max1;
    }
};
int main()
{}
