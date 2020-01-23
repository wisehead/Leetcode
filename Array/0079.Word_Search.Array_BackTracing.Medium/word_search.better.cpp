/*******************************************************************************
 *      file name: word_search.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/26-09:34:47                              
 *  modified time: 2019/03/26-09:34:47                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool dfs(vector<vector<char>>& board, int i, int j, string word)
	{
        //cout<<"i:"<<i<<"    j:"<<j<<"   word:"<<word<<endl;
		int len = word.length();
		if (!len) return true;
		int m = board.size();
		int n = board[0].size();
        char record = board[i][j];
		board[i][j] = 0;
		string str = word.substr(1, len - 1);
		//east
		if (j+1 < n && board[i][j+1] == word[0])
			if (dfs(board, i, j+1, str)) return true;
		//south
		if (i+1 < m && board[i+1][j] == word[0])
			if (dfs(board, i+1, j, str)) return true;
		//west
		if (j-1 >= 0 && board[i][j-1] == word[0])
			if (dfs(board, i, j-1, str)) return true;
		//north
		if  (i-1 >= 0 && board[i-1][j] == word[0])
			if (dfs(board, i-1, j, str)) return true;
        board[i][j] = record;
		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{
					string str = word.substr(1, word.length() - 1);
					if (dfs(board, i, j, str))
						return true;
				}
			}
		}
		return false;
    }
};
int main()
{}
