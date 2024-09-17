/*******************************************************************************
 *      file name: rotate_image.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/06-10:23:15                              
 *  modified time: 2019/03/06-10:23:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
		vector<vector<int> > res(matrix); 
		int n = matrix.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				res[i][j] = matrix[n - j - 1][i];
			}
		}
		matrix.swap(res);
    }
};
int main()
{}
