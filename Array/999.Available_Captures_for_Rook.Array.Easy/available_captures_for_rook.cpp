/*******************************************************************************
 *      file name: available_captures_for_rook.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/08-12:27:18                              
 *  modified time: 2019/07/08-12:27:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& A) {
		int n = A.size();
		int cnt = 0;
		int pos_x = 0, pos_y = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (A[i][j] == 'R')
				{
					pos_x = i;
					pos_y = j;
					break;
				}
			}
		}
		// north
		for (int i = pos_x - 1; i >= 0; i--)
		{
			if (A[i][pos_y] == 'B')
				break;
			if (A[i][pos_y] == 'p')
			{
				cnt++;
				break;
			}
		}
        //cout<<"north cnt:"<<cnt<<endl;
		// south 
		for (int i = pos_x + 1; i < n; i++)
		{
			if (A[i][pos_y] == 'B')
				break;
			if (A[i][pos_y] == 'p')
			{
				cnt++;
				break;
			}
		}
        //cout<<"south cnt:"<<cnt<<endl;

		// east 
		for (int j = pos_y + 1; j < n; j++)
		{
			if (A[pos_x][j] == 'B')
				break;
			if (A[pos_x][j] == 'p')
			{
				cnt++;
				break;
			}
		}
        //cout<<"east cnt:"<<cnt<<endl;
		// west 
		for (int j = pos_y - 1; j >= 0; j--)
		{
			if (A[pos_x][j] == 'B')
				break;
			if (A[pos_x][j] == 'p')
			{
				cnt++;
				break;
			}
		}
        //cout<<"west cnt:"<<cnt<<endl;
		return cnt;
    }
};
int main()
{}
