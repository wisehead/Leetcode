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
	string tictactoe(vector<vector<int>>& moves) {
		int n=3;
		vector<vector<int>> board(n,vector<int>(n));
		int sum=0,sum2=0;
		for(int i=0;i<moves.size();i++)
		{
			int r=moves[i][0];
			int c=moves[i][1];
			if(i%2==0)
				board[r][c]=1;
			else
				board[r][c]=-1;

			if(r==c)
				sum=sum+board[r][c];
			if(r+c==n-1)
				sum2=sum2+board[r][c];
		}
		if(sum==n||sum2==n)
			return "A";
		else if(sum==-n||sum2==-n)
				return "B";
		for(int i=0;i<n;i++)
		{
			sum=0;sum2=0;
			for(int j=0;j<n;j++)
			{
				sum=sum+board[i][j];
				sum2=sum2+board[j][i];
			}
			if(sum==n||sum2==n)
			return "A";
			else if(sum==-n||sum2==-n)
				return "B";
		}
		if(moves.size()==n*n)
			return "Draw";
		else
			return "Pending";
	}
};
int main()
{}
