/*******************************************************************************
 *      file name: pacific_atlantic_water_flow.fail.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/26-18:02:44                              
 *  modified time: 2022/01/26-18:02:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int M = heights.size();
        int N = heights[0].size();        
        vector<vector<int>> res;
        vector<vector<bool>> pac(M, vector<bool>(N, false));
        vector<vector<bool>> atl(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            pac[i][0] = true;
            atl[i][N-1] = true;
        }
        for (int j = 0; j < N; j++) {
            pac[0][j] = true;
            atl[M-1][j] = true;
        }
        vector<vector<bool>> visit_pac(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                dfs(heights, pac, visit_pac, i,j);
            }
        }     
        vector<vector<bool>> visit_atl(M, vector<bool>(N, false));
        for (int i = M-1; i >= 0; i--) {
            for (int j = N-1; j >= 0; j--) {
                dfs2(heights, atl, visit_atl, i,j);
            }
        }    
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout<<"i:"<<i<<",j:"<<j<<",pac:"<<pac[i][j]<<", atl:"<<atl[i][j]<<endl;
                if (pac[i][j] && atl[i][j]) {
                    vector<int> vec(2,0);
                    vec[0] = i; vec[1] = j;
                    res.push_back(vec);
                }
            }
        }           
        return res;
    }
    
    bool dfs(vector<vector<int>>& heights, vector<vector<bool>>& pac, vector<vector<bool>>& visited,int i, int j) {
        int M = heights.size();
        int N = heights[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N) return false;
        if (visited[i][j]) return pac[i][j];
        if (pac[i][j]) {
            visited[i][j] = true;
            return true;
        }
        visited[i][j] = true;
        if (dfs(heights, pac, visited, i,j-1) && heights[i][j-1] <= heights[i][j]) {
            pac[i][j] = true;
            return true;            
        }         

        
        if (dfs(heights, pac, visited, i-1, j) && heights[i-1][j] <= heights[i][j]) {
            pac[i][j] = true;
            return true;
        }

        if (dfs(heights, pac, visited, i,j+1) && heights[i][j+1] <= heights[i][j]) {
            pac[i][j] = true;
            return true;            
        }         

        if (dfs(heights, pac, visited, i+1, j) && heights[i+1][j] <= heights[i][j]) {
            pac[i][j] = true;
            return true;
        }  
        return false;
    }
    bool dfs2(vector<vector<int>>& heights, vector<vector<bool>>& pac, vector<vector<bool>>& visited,int i, int j) {
        int M = heights.size();
        int N = heights[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N) return false;
        if (visited[i][j]) return pac[i][j];
        if (pac[i][j]) {
            visited[i][j] = true;
            return true;
        }
        visited[i][j] = true;


        if (dfs2(heights, pac, visited, i,j+1) && heights[i][j+1] <= heights[i][j]) {
            pac[i][j] = true;
            return true;            
        }         

        if (dfs2(heights, pac, visited, i+1, j) && heights[i+1][j] <= heights[i][j]) {
            pac[i][j] = true;
            return true;
        }  
        if (dfs2(heights, pac, visited, i,j-1) && heights[i][j-1] <= heights[i][j]) {
            pac[i][j] = true;
            return true;            
        }         

        
        if (dfs2(heights, pac, visited, i-1, j) && heights[i-1][j] <= heights[i][j]) {
            pac[i][j] = true;
            return true;
        }        
        return false;
    }    
};
int main()
{}
