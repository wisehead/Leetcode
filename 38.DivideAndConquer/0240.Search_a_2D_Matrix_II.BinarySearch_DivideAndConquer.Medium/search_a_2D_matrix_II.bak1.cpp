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
        cout<<"l_m:"<<l_m<<"    r_m:"<<r_m<<"   l_n:"<<l_n<<"   r_n:"<<r_n<<endl;
        if (l_m >= r_m) return false;
        if (l_n >= r_n) return false;
        int mid_m = (l_m + r_m)/2;//纵坐标
        int mid_n = (l_n + r_n)/2;//横坐标
        
        int pivot =matrix[0][mid_n];
        if (pivot == target) return true;
        if (target > pivot) l_n = mid_n;
        else r_n = mid_n;
        
        pivot = matrix[mid_m][mid_n];
        if (pivot == target) return true;
        if (target > pivot) l_m = mid_m;
        else r_m = mid_m;
        
        return bs(matrix, l_m, r_m, l_n, r_n, target);
    }
};
int main()
{
}
