/*******************************************************************************
 *      file name: projection_area_of_3D_shapes.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/08-19:34:49                              
 *  modified time: 2019/01/08-19:34:49                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int projectionArea(vector<vector<int> >& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int area_z = 0; 
		int area_y = 0;//max row value 
		int area_x = 0;//max column value
		for (int i=0; i<m; i++)
		{
			int max_row_val = 0;
			for (int j=0; j<n; j++)
			{
				if (grid[i][j] > max_row_val)
					max_row_val = grid[i][j];
                if (grid[i][j] > 0) area_z++;
			}
			area_y += max_row_val;
		}

		for (int j=0; j<n; j++)
		{
			int max_col_val = 0;
			for (int i=0; i<m; i++)
			{
				if (grid[i][j] > max_col_val)
					max_col_val = grid[i][j];
			}
			area_x += max_col_val;
		}
		return (area_x + area_y + area_z);
    }
};
int main()
{}
