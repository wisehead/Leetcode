/*******************************************************************************
 *      file name: magic_squares_in_grid.cpp                                               
 *         author: Hui Chen. ic) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/18-15:53:52                              
 *  modified time: 2018/12/18-15:53:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(int x) {
        return (x < 10 and x > 0);
    }
	bool check3And3(vector<vector<int> >& grid, int i, int j) {
        if (  !isValid(grid[i][j])
            ||!isValid(grid[i][j+1])
            ||!isValid(grid[i][j+2])
            ||!isValid(grid[i+1][j])
            ||!isValid(grid[i+1][j+1])
            ||!isValid(grid[i+1][j+2])
            ||!isValid(grid[i+2][j])
            ||!isValid(grid[i+2][j+1])
            ||!isValid(grid[i+2][j+2])
           )
            return false;
		int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
		return (  (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] == sum)
				&&(grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] == sum)
				&&(grid[i][j] + grid[i+1][j] + grid[i+2][j] == sum)
				&&(grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] == sum)
				&&(grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] == sum)
				&&(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] == sum)
				&&(grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] == sum)
				);
	}

    int process3Lines(vector<vector<int> >& grid, int i) {
		int count = 0;
		int size = grid[0].size();
		for (int j = 0; j < size - 2; j++)
		{
			if ((j+1 >=  size -1) ||  (j+2 >= size))
				break;
			int sum_y = grid[i][j] + grid[i+1][j] + grid[i+2][j];
			int sum_x = grid[i][j] + grid[i][j+1] + grid[i][j+2];
			if (sum_x == sum_y)
			{
				if (check3And3(grid, i, j))
					count++;
			}
		}
		return count;
    }

    int numMagicSquaresInside(vector<vector<int> >& grid) {
		int size = grid.size();
		int count = 0;
		for (int i = 0; i < size - 2; i++)
		{
			if ((i+1 >=  size -1) ||  (i+2 >= size))
				break;
			int temp = process3Lines(grid, i);
			count += temp;
		}
		return count;
    }
};

int main()
{}
