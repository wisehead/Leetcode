/*******************************************************************************
 *      file name: rotting_oranges.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/22-13:31:36                              
 *  modified time: 2019/02/22-13:31:36                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct Position {
	int i;
	int j;
} Pos;

class Solution {
public:
	bool check_bound(int x, int y) {
		return (x >= 0 && x < x_max && y >= 0 && y < y_max); 
	}
    void bfs_internal(vector<vector<int> >& grid, int i, int j, queue<Pos> &q) {
		if (!check_bound(i, j)) return;
		if (grid[i][j] == 2 || grid[i][j] == 0) return;
		grid[i][j] = 2;
		Pos pos;
		pos.i = i;
		pos.j = j;
		q.push(pos);
	}
    void bfs(vector<vector<int> >& grid, int i, int j, queue<Pos> &q) {
		bfs_internal(grid, i-1, j, q);//north
		bfs_internal(grid, i, j-1, q);//north
		bfs_internal(grid, i+1, j, q);//east
		bfs_internal(grid, i, j+1, q);//south
	}
    int orangesRotting(vector<vector<int> >& grid) {
		x_max = grid.size(); 
		y_max = grid[0].size(); 
		_cnt = 0;
		int count = 0;
		int steps = 0;
		queue<Pos> q1;
		queue<Pos> q2;
		for (int x = 0; x < x_max; x++)
		{
			for (int y = 0; y < y_max; y++)
			{
				if (grid[x][y] != 0)
				{
					count++;
					if (grid[x][y] == 2)
					{
						Pos pos;
						pos.i = x;
						pos.j = y;
						q1.push(pos);
					}
				}	
			}
		}
        if (count == 0) return 0;
		int sum = 0; 
		while (!q1.empty())
		{
			steps++;
			sum += q1.size();
			while (!q1.empty())
			{
				Pos pos = q1.front();
				q1.pop();
				bfs(grid, pos.i, pos.j, q2);
			}
			swap(q1, q2);
		}
		if (sum == count)
			return steps - 1;
		return -1;
    }
private:
	int x_max;
	int y_max;
	int _cnt;
};
int main()
{}
