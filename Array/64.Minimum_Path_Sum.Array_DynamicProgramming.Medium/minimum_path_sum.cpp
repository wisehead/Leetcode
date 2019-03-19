/*******************************************************************************
 *      file name: minimum_path_sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/19-09:25:25                              
 *  modified time: 2019/03/19-09:25:25                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<unsigned long long> vec(n, 0);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0)
				{
					if (j == 0)
						vec[j] = grid[i][j];
					else
						vec[j] = vec[j-1] + grid[i][j];
				}
				else
				{
					if (j == 0)
						vec[j] = vec[j] + grid[i][j];
					else
						vec[j] = min(vec[j-1], vec[j]) + grid[i][j];
				}
			}
		}
		return vec[n-1];
    }
};
int main()
{}
