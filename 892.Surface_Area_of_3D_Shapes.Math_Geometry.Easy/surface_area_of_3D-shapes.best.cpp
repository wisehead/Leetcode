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
    int surfaceArea(vector<vector<int> > grid) {
        int res = 0, n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) res += grid[i][j] * 4 + 2;
                if (i) res -= min(grid[i][j], grid[i - 1][j]) * 2;
                if (j) res -= min(grid[i][j], grid[i][j - 1]) * 2;
            }
        }
        return res;
    }
};
int main()
{}
