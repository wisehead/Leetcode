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
enum Direction { EAST, NORTH, WEST, SOUTH } d;
class Solution {
public:
	bool check_bound(int i, int j, int m, int n) {
		return ((i >=0 & i < m) && (j >= 0 && j < n));
	}
    int surfaceArea(vector<vector<int> >& grid) {
		int dirs[4][2] = {{1, 0},{0,1}, {-1, 0},{0, -1}};
		int m = grid.size();
		int n = grid[0].size();
		int sum = 0;
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (grid[i][j] == 0) continue;
				int area = grid[i][j] * 4 + 2;
				for (int k=0; k<4; k++)
				{
					int x = i + dirs[k][0];
					int y = j + dirs[k][1];
					if (check_bound(x,y,m,n))
					{
						int delta = min(grid[x][y], grid[i][j]);
						area -= delta;
					}
				}
				sum += area;
			}
		}
		return sum;
    }
};
int main()
{}
