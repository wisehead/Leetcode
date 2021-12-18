/*******************************************************************************
 *      file name: matrix_diagonal_sum.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/18-10:55:21                              
 *  modified time: 2021/12/18-10:55:21                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int N = mat.size();
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += mat[i][i];
            sum += mat[i][N-1-i];
        }
        if (N%2) {
            int x = (N-1)/2;
            sum -= mat[x][x];
        }
        return sum;
    }
};
int main()
{}
