/*******************************************************************************
 *      file name: unique_paths_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/18-18:11:43                              
 *  modified time: 2019/03/18-18:11:43                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		for (int i = 0; i < m; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < n; j++)
				{
					if (obstacleGrid[i][j] != 0)
						obstacleGrid[i][j] = 0;
					else 
						obstacleGrid[i][j] = 1;
				}
				continue;
			}
			for (int j = 0; j < n; j++)
			{
				if (j == 0)
				{
					if (obstacleGrid[i][j] != 0)
						obstacleGrid[i][j] = 0;
					else 
						obstacleGrid[i][j] = 1;
					continue;
				}
				if (obstacleGrid[i][j] != 0)
					obstacleGrid[i][j] = 0;
				else 
					obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
			}
		}
		return obstacleGrid[m-1][n-1];
    }
};
int main()
{}
