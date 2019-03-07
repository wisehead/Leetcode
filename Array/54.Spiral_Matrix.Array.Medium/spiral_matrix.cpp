/*******************************************************************************
 *      file name: spiral_matrix.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/07-09:27:29                              
 *  modified time: 2019/03/07-09:27:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
		vector<int> res;
		//m for i&y, j for n & x 
		int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;
        
		vector<vector<int> > flags(matrix);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				flags[i][j] = 0;
		int i = 0, j = 0;
		int last_i = 0, last_j = 0;
		flags[i][j] = 1;
        res.push_back(matrix[i][j]);
		while(1)
		{
			last_i = i;
			last_j = j;
			//east
		   while (j+1 < n && !flags[i][j+1])	
		   {
			   j++;
			   flags[i][j] = 1;
			   res.push_back(matrix[i][j]);
		   }
		   //south
		   while (i+1 < m && !flags[i+1][j])	
		   {
			   i++;
			   flags[i][j] = 1;
			   res.push_back(matrix[i][j]);
		   }
			//west
		   while (j-1 >= 0 && !flags[i][j-1])	
		   {
			   j--;
			   flags[i][j] = 1;
			   res.push_back(matrix[i][j]);
		   }
		   //north
		   while (i-1 >= 0 && !flags[i-1][j])	
		   {
			   i--;
			   flags[i][j] = 1;
			   res.push_back(matrix[i][j]);
		   }
		   if (i == last_i && j == last_j)
			   break;
		}
		return res;
    }
};
int main()
{}
