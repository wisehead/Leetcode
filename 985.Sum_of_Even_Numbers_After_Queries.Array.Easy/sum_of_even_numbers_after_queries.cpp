/*******************************************************************************
 *      file name: sum_of_even_numbers_after_queries.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/19-13:50:21                              
 *  modified time: 2019/02/19-13:50:21                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int> >& queries) {
		int size = queries.size();
		int sum = 0;
		vector<int> res;
		for (auto &e : A)
		{
			if (e % 2 == 0) sum += e;
		}
		for (int i = 0; i < size; i++)
		{
			int val = queries[i][0];
			int index = queries[i][1];
			if (A[index] % 2 == 0)
				sum -= A[index];
			A[index] += val;
			if (A[index] % 2 == 0)
				sum += A[index];
			res.push_back(sum);
		}
		return res;
    }
};
int main()
{}
