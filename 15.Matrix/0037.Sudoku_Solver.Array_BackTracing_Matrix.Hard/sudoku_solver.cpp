/*******************************************************************************
 *      file name: sudoku_solver.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/09-17:10:42                              
 *  modified time: 2021/08/09-17:10:42                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    void mark(vector<vector<char>>& board, int i, int j, char x) {
        A[i].insert(x);
        B[j].insert(x);
        C[i/3][j/3].insert(x);        
    }

    void clear(vector<vector<char>>& board, int i, int j, char x) {
        A[i].erase(x);
        B[j].erase(x);
        C[i/3][j/3].erase(x);        
    }
    
    bool is_in(vector<vector<char>>& board, int i, int j, char x) {
        if (A[i].count(x)) return true;
        if (B[j].count(x)) return true;
        if (C[i/3][j/3].count(x)) return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y) {
        for (int i = x; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    //cout<<"i:"<<i<<",j:"<<j<<endl;
                    for (int c = '1'; c <= '9' ; c++) {
                        if (!is_in(board,i,j,c)) {
                            mark(board, i, j, c);
                            board[i][j] = c;
                            bool ret = dfs(board, i, j);
                            if (ret) return true;
                            board[i][j] = '.';
                            clear(board, i, j,c);
                        }
                    }
                    return false;
                }
            }
        }    
        return true;
    }
    
    
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                mark(board, i, j, board[i][j]);
            }
        }
        bool ret = dfs(board,0,0);
        /*
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout <<board[i][j]<<",";
            }
            cout<<endl;
        }
        */
        return ret;
    }
private:
    set<char> A[9];//横的
    set<char> B[9];//竖的
    set<char> C[3][3];//sub box
};
int main()
{}
