/*******************************************************************************
 *      file name: spirial_matrix.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/14-10:34:16                              
 *  modified time: 2019/03/14-10:34:16                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res;
		//m for i&y, j for n & x 
		int cnt = 0;
		int i = 0, j = 0;
		int last_i = 0, last_j = 0;
		for (int k = 0; k < n; k++)
		{
			vector<int> vec(n, 0);
			res.push_back(vec);
		}
        res[0][0] = ++cnt;
		while(1)
		{
			last_i = i;
			last_j = j;
			//east
		   while (j+1 < n && !res[i][j+1])	
		   {
			   j++;
			   res[i][j] = ++cnt;
		   }
		   //south
		   while (i+1 < n && !res[i+1][j])	
		   {
			   i++;
			   res[i][j] = ++cnt;
		   }
			//west
		   while (j-1 >= 0 && !res[i][j-1])	
		   {
			   j--;
			   res[i][j] = ++cnt;
		   }
		   //north
		   while (i-1 >= 0 && !res[i-1][j])	
		   {
			   i--;
			   res[i][j] = ++cnt;
		   }
		   if (i == last_i && j == last_j)
			   break;
		}
		return res;

    }
};
int main()
{}
