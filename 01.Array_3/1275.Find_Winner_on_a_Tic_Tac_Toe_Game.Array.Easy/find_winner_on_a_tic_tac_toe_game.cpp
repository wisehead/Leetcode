/*******************************************************************************
 *      file name: find_winner_on_a_tic_tac_toe_game.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/12/26-11:48:23                              
 *  modified time: 2020/12/26-11:48:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string tictactoe(vector<vector<int> >& moves) {
		int A[3][3] = {0};
		for (int i = 0; i < moves.size(); i++) {
			if (i % 2 == 0) A[moves[i][0]][moves[i][1]] = 1;
			else A[moves[i][0]][moves[i][1]] = 2;	
		}

		for (int i = 0; i < 3; i++) {
			if (A[i][0] == A[i][1] == A[i][2]) {
				if (A[i][0] == 1) return "A";
				else if (A[i][0] == 2) return "B";
			}
		}
		for (int j = 0; j < 3; j++) {
			if (A[0][j] == A[1][j] == A[2][j]) {
				if (A[0][j] == 1) return "A";
				else if (A[0][j] == 2) return "B";
			}
		}
		if (A[0][0] == A[1][1] == A[2][2] || A[0][2] == A[1][1] == A[2][0]) {
			if (A[1][1] == 1) return "A";
			else if (A[1][1] == 2) return "B";
		}
		if (moves.size() < 9) return "Pending";
		return "Draw";
    }
};
int main()
{}
