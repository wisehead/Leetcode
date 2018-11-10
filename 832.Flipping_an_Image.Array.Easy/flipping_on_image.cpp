/*******************************************************************************
 *      file name: flipping_on_image.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/10-14:44:31                              
 *  modified time: 2018/11/10-14:44:31                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
		vector<vector<int> > res;
		int m = A.size();
		int n = A[0].size();
		for (int i = 0; i < m; i++)
		{
			vector<int> vec = A[i];
			vector<int> vec_out;
			for (int j = n-1; j >=0 ; j--)
			{
				vec_out.push_back(1 - vec[j]);
			}
			res.push_back(vec_out);
		}
		return res;
    }
};
int main()
{}
