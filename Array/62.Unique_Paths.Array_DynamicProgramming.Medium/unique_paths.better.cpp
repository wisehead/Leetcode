/*******************************************************************************
 *      file name: unique_paths.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/15-14:24:35                              
 *  modified time: 2019/03/15-14:24:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        // base dp
        for (int i = 0; i < m; i++)
            dp[i][0] = 1; // there are only one way to cells of column 0, from moving down
        
        for (int i = 0; i < n; i++)
            dp[0][i] = 1; // there are only one way to cells of row 0, from moving right
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // number of ways of cell(i, j) = number of ways from moving down + number of ways from moving right
        
        return dp[m-1][n-1];
    }
};
int main()
{}
