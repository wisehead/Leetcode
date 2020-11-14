/*******************************************************************************
 *      file name: search_a_2D_matrix_II.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/02-19:44:53                              
 *  modified time: 2020/11/02-19:44:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size_m = matrix.size();
        if (size_m == 0) return false;
        int size_n = matrix[0].size();
        if (size_n == 0) return false;
        
        return bs(matrix, 0, size_m, 0, size_n, target);
    }

    bool bs(vector<vector<int>>& matrix, int l_m, int r_m,  int l_n, int r_n, int target) {
        //cout<<"l_m:"<<l_m<<"    r_m:"<<r_m<<"   l_n:"<<l_n<<"   r_n:"<<r_n<<endl;
        if (r_m == 0 || r_n == 0) {
            if (r_m == 0 && r_n == 0) {
                return matrix[0][0] == target;
            }
            if (r_m == 0) r_m = 1;
            if (r_n == 0) r_n = 1;
        }

        if (matrix[r_m-1][r_n-1] == target) return true;
        if (matrix[r_m-1][r_n-1] < target) return false;
        int j = bs2(matrix[r_m-1], target);
        if (matrix[r_m-1][j] == target) return true;
        vector<int> vec;
        for (int i = 0; i < matrix.size(); i++) 
            vec.push_back(matrix[i][r_n-1]);
        int i = bs2(vec, target);
        if (vec[i] == target) return true;
        //cout<<"i:"<<i<<"    j:"<<j<<endl;
        return bs(matrix, i, r_m-1, j, r_n-1, target);
    }
    int bs2(vector<int> vec, int target) {
        int l = 0, r = vec.size(), mid = 0;
        while (l < r) {
            mid = (l+r)/2;
            if (vec[mid] == target) return mid;
            if (target > vec[mid]) 
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
    
};
int main()
{
}
