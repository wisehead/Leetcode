/*******************************************************************************
 *      file name: toeplitz_matrix.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/05-12:05:02                              
 *  modified time: 2018/10/05-12:05:02                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool checkBoundary(int i, int j, int i_max, int j_max) {
		return (i >= 0 && i < i_max && j >= 0 && j < j_max);
	}
    bool isToeplitzMatrix(vector<vector<int> >& matrix) {
		int i_max = matrix.size();
		int j_max = matrix[0].size();
		for (int m = 0; m < i_max; m++) 
		{
			int val = matrix[m][0];
			for (int i = m, j = 0; i < i_max && j < j_max; i++, j++)
			{
				if (matrix[i][j] != val)
					return false;
			}
		}
		for (int n = 0; n < j_max; n++) 
		{
			int val = matrix[0][n];
			for (int i = 0, j = n; i < i_max && j < j_max; i++, j++)
			{
				if (matrix[i][j] != val)
					return false;
			}
		}
		return true;
    }
};
int main()
{}
