/*******************************************************************************
 *      file name: search_a_2D_matrix.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/21-09:33:30                              
 *  modified time: 2019/03/21-09:33:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        if(matrix[0].empty()) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int start_i = 0, end_i = m - 1, mid = 0;
		while (start_i < end_i)
		{
            mid = (start_i + end_i)/2;
			if (target == matrix[mid][0])
				return true;
			if (target > matrix[mid][0])
				start_i = mid + 1;
			else
				end_i = mid;
		}
        if (start_i && matrix[start_i][0] > target) start_i--;
		int left = 0, right = n - 1;
		while (left < right)
		{
			mid = (left + right)/2;
			if (target == matrix[start_i][mid])
				return true;
			if (target > matrix[start_i][mid])
				left = mid + 1;
			else
				right = mid;
		}
        return (target == matrix[start_i][left]);
    }
};
int main()
{}
