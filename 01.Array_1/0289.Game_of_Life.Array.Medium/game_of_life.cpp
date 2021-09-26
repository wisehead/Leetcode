/*******************************************************************************
 *      file name: game_of_life.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/17-21:23:51                              
 *  modified time: 2019/04/17-21:23:51                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int get(vector<vector<int>> array,int i, int j)
	{
		if (i >= 0 && i < m && j >= 0 && j < n)
		{
			return array[i][j];
		}
		return 0;
	}
    void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty())
			return;
		m = board.size();
		n = board[0].size();
		for (int i = 0; i < m; i++)
		{
			vector<int> vec;
			for (int j = 0; j < n; j++)
			{
				int nbs = get(board, i-1, j-1) + get(board,i-1,j) + get(board,i-1,j+1) \
					+ get(board,i,j-1) + get(board,i,j+1) \
					+ get(board,i+1,j-1) + get(board,i+1,j) + get(board,i+1,j+1); 
				int cell = 0;
                //cout<<"i:"<<i<<"    j:"<<j<<"   board[i][j]:"<<board[i][j]<<"   nbs:"<<nbs<<endl;
				if (board[i][j])
				{
					if (nbs == 2 || nbs == 3)
						cell = 1;
				}
				else if (nbs == 3)
					cell = 1;
				vec.push_back(cell);
			}
			board.push_back(vec);
		}
		board.erase(board.begin(), board.begin()+m);
    }
private:
	int m;
	int n;
};
int main()
{}
