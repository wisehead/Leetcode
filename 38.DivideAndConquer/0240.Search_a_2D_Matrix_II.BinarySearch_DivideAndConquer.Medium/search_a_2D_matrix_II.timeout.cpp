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
        
        for (auto vec : matrix) {
            int size = vec.size();
            if (vec[0] > target || vec[size-1] < target) continue;
            if (bs(vec, target)) return true; 
        }
        return false;
    }
    
    int bs(vector<int> vec, int target) {
        int l = 0, r = vec.size(), mid = 0;
        while (l < r) {
            mid = (l+r)/2;
            if (vec[mid] == target) return true;
            if (target > vec[mid]) 
                l = mid + 1;
            else 
                r = mid;
        }
        return false;
    }
};
int main()
{}
