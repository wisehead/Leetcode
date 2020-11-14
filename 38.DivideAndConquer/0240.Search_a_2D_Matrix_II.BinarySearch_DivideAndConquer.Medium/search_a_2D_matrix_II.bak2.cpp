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
        if (l_m > r_m) return false;

        if (l_n > r_n) return false;
        //if (l_m >= matrix.size() && l_n >= matrix[0].size()) return false;
        if (l_m == r_m || l_n == r_n) {
            /*
            if (l_m == r_m && l_n == r_n) {
                return matrix[l_m][l_n] == target;
            }*/
            
            if (l_m == r_m) {
                if (l_m >= matrix.size()) l_m--;
                if (bs2(matrix[l_m], target)) return true;
            } 
            
            if (l_n == r_n)   
            {
                if (l_n >= matrix[0].size()) l_n--;
                    vector<int> vec;
                    for (int i = 0; i < matrix.size(); i++) 
                        vec.push_back(matrix[i][l_n]);
                    if (bs2(vec, target)) return true;

            }
            return false;
        }    
        
        int mid_m = (l_m + r_m)/2;//纵坐标
        int mid_n = (l_n + r_n)/2;//横坐标
        
        int pivot =matrix[mid_m][mid_n];
        if (pivot == target) return true;
        if (target > pivot) {
            l_n = mid_n+1;
            l_m = mid_m+1;
        }
        else {
            r_n = mid_n;
            r_m = mid_m;
        }
        
        return bs(matrix, l_m, r_m, l_n, r_n, target);
    }
    int bs2(vector<int> vec, int target) {
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
{
}
