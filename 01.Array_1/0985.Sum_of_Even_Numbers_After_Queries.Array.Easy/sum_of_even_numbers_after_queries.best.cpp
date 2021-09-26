/*******************************************************************************
 *      file name: sum_of_even_numbers_after_queries.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/19-13:50:21                              
 *  modified time: 2019/02/19-13:50:21                              
 *******************************************************************************/
#include <iostream>
#include <vector>
//#include <algorithm>
#include <numeric>  
using namespace std;
class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& qs, vector<int> res = {}) {
	  int sum = accumulate(begin(A), end(A), 0, [](int s, int a) { return s + (a % 2 == 0 ? a : 0); });
	  for (auto &q : qs) {
		if (A[q[1]] % 2 == 0) sum -= A[q[1]];
		A[q[1]] += q[0];
		if (A[q[1]] % 2 == 0) sum += A[q[1]];
		res.push_back(sum);
	  }
	  return res;
	}
};
int main()
{}
