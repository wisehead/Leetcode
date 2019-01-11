/*******************************************************************************
 *      file name: surface_area_of_3D-shapes.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/11-09:57:24                              
 *  modified time: 2019/01/11-09:57:24                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool check_bound(int i, int j, int m, int n) {
		return ((i >=0 & i < m) && (j >= 0 && j < n));
	}
    int surfaceArea(vector<vector<int> >& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int sum = 0;
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (grid[i][j] == 0) continue;
				int area = grid[i][j] * 4 + 2;
				//north
				if (check_bound(i,j+1,m,n))
				{
					int delta = min(grid[i][j+1], grid[i][j]);
					area -= delta;
				}

				//east
				if (check_bound(i+1,j,m,n))
				{
					int delta = min(grid[i+1][j], grid[i][j]);
					area -= delta;
				}

				//south
				if (check_bound(i,j-1,m,n))
				{
					int delta = min(grid[i][j-1], grid[i][j]);
					area -= delta;
				}

				//west
				if (check_bound(i-1,j,m,n))
				{
					int delta = min(grid[i-1][j], grid[i][j]);
					area -= delta;
				}
				sum += area;
			}
		}
		return sum;
    }
};
int main()
{}
