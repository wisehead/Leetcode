/*******************************************************************************
 *      file name: max_area_of_island.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/19-22:38:06                              
 *  modified time: 2018/09/19-22:38:06                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int dfs(vector<vector<int> > &grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        //cout<<"i:"<<i<<"    j:"<<j<<endl;
		if (i < 0 || i >= m || j >= n || j < 0) return 0;
		if (grid[i][j] == 0) return 0;
		//int sum = 1;
		grid[i][j] = 0;
		int sum = 1 + dfs(grid, i - 1, j) + dfs(grid,i+1,j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
        //cout<<"sum for i:"<<i<<"    j:"<<j<<"   is:"<<sum<<endl;
        return sum;
	}
    int maxAreaOfIsland(vector<vector<int> >& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int max = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j=0; j < n; j++)
			{
				if (grid[i][j] == 1)
				{
					int sum = dfs(grid, i, j);
					if (sum > max) max = sum;
				}
			}
		}
		return max;
    }
};
int main()
{}
