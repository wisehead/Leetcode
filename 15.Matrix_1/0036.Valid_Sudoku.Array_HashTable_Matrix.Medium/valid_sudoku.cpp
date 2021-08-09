/*******************************************************************************
 *      file name: valid_sudoku.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/09-19:29:31                              
 *  modified time: 2021/08/09-19:29:31                              
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

    bool is_in(vector<vector<char>>& board, int i, int j, char x) {
        if (A[i].count(x)) return true;
        if (B[j].count(x)) return true;
        if (C[i/3][j/3].count(x)) return true;
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int c = board[i][j];
                if (c != '.') {
                    if (is_in(board, i, j, c)) return false;
                    mark(board, i, j, board[i][j]);                    
                }

            }
        }
        return true;
    }
private:
    set<char> A[9];//横的
    set<char> B[9];//竖的
    set<char> C[3][3];//sub box
};
int main()
{}
