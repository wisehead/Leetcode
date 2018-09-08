/*******************************************************************************
 *      file name: image_smoother.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/08-16:52:58                              
 *  modified time: 2018/09/08-16:52:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        if (m == 0 || n == 0) return {{}};
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = M[i][j], cnt = 1;
                for (int k = 0; k < dirs.size(); k++) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x < 0 || x > m - 1 || y < 0 || y > n - 1) continue;
                    sum += (M[x][y] & 0xFF);
                    cnt++;
                }
                M[i][j] |= ((sum / cnt) << 8);
            }
        }
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] >>= 8;
            }
         }
        return M;
    }
	
};
                   
int main()
{}
