/*******************************************************************************
 *      file name: set_matrix_zeroes.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/20-09:43:26                              
 *  modified time: 2019/03/20-09:43:26                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		set<int> si, sj;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!matrix[i][j])
				{
					si.insert(i);
					sj.insert(j);
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (si.count(i) || sj.count(j))
					matrix[i][j] = 0;
			}
		}
    }
};
int main()
{}
