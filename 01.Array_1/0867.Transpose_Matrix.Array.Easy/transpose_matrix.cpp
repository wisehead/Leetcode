/*******************************************************************************
 *      file name: transpose_matrix.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/30-21:35:08                              
 *  modified time: 2018/12/30-21:35:08                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int> >& A) {
		int len_M = A.size();
		int len_N = A[0].size();
		vector<vector<int> > res;
		for (int j = 0; j < len_N; j++)
		{
			vector<int> vec;
			for (int i = 0; i < len_M; i++)
			{
				vec.push_back(A[i][j]);
			}
			res.push_back(vec);
		}
		return res;
    }
};
int main()
{}
