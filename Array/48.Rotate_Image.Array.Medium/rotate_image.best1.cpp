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
	/*
	 * clockwise rotate
	 * first reverse up to down, then swap the symmetry 
	 * 1 2 3     7 8 9     7 4 1
	 * 4 5 6  => 4 5 6  => 8 5 2
	 * 7 8 9     1 2 3     9 6 3
	*/
	void rotate(vector<vector<int> > &matrix) {
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i + 1; j < matrix[i].size(); ++j)
				swap(matrix[i][j], matrix[j][i]);
		}
	}
};
int main()
{}
