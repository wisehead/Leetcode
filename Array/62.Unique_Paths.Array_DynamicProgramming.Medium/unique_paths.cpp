/*******************************************************************************
 *      file name: unique_paths.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/15-14:24:35                              
 *  modified time: 2019/03/15-14:24:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int> > matrix;
		vector<int> vec0(n, 1);
		matrix.push_back(vec0);
		for (int i = 1; i < m; i++)
		{
			vector<int> vec(n, 0);
			vec[0] = 1;
			for (int j = 1; j < n; j++)
			{
				vec[j] = vec[j-1] + matrix[i-1][j];
			}
			matrix.push_back(vec);
		}
		return matrix[m-1][n-1];
    }
};
int main()
{}
