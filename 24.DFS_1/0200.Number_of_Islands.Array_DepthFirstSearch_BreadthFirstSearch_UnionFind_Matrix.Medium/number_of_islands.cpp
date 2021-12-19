/*******************************************************************************
 *      file name: number_of_islands.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/19-15:51:28                              
 *  modified time: 2021/12/19-15:51:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<bool>> visit(M, vector<bool>(N, false));
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j]=='1' && !visit[i][j]) {
                    cnt++;
                    dfs(grid, visit, i, j);
                }
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int i, int j) {
        int M = grid.size();
        int N = grid[0].size();
        if (grid[i][j] == '0') return;
        else {
            if (visit[i][j]) return;
            else visit[i][j] = true;
        }
        if (i-1 >= 0) dfs(grid, visit, i-1, j);
        if (j+1 < N) dfs(grid, visit, i, j+1);
        if (i+1 < M) dfs(grid, visit, i+1, j);
        if (j-1 >= 0) dfs(grid, visit, i, j-1);
    }
};
int main()
{}
