/*******************************************************************************
 *      file name: ballteship_in_a_board.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/26-12:48:02                              
 *  modified time: 2022/01/26-12:48:02                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int M = board.size();
        int N = board[0].size();      
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs(board,visited, i,j)) cnt++;
            }
        }
        return cnt;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        int M = board.size();
        int N = board[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N) return 0;
        if (visited[i][j]) return false;
        if (board[i][j] == '.') {
            visited[i][j] = true;
            return false;
        }
        visited[i][j] = true;
        dfs(board, visited, i-1, j);
        dfs(board, visited, i, j+1);
        dfs(board, visited, i+1, j);
        dfs(board, visited, i, j-1);
        return true;
    }
};
int main()
{}
