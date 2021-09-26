/*******************************************************************************
 *      file name: shift_2D_grid.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/27-09:51:36                              
 *  modified time: 2020/11/27-09:51:36                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();    
        for (int x = 0; x < k; x++) {
            vector<int> vec(m, 0);
            for (int j = n-1; j >= 0; j--) {
                if (j == n-1) {
                    for (int i = 0; i < m; i++) {
                        vec[(i+1)%m] = grid[i][j];
                    }
                    continue;
                }
                for (int i = 0; i < m; i++) {
                    grid[i][j + 1] = grid[i][j];
                }
            }
            for (int i = 0; i < m; i++) {
                grid[i][0] = vec[i];
            }               
        }
        return grid;
    }
};
int main()
{}
