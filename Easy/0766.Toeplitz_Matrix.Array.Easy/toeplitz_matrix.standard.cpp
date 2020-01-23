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
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
}int main()
{}
