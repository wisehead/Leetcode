/*******************************************************************************
 *      file name: determine_whether_matrix_can_be_obtained_by_rotation.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/19- 9:09                                    
 * modified time: 24/09/19- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        auto temp = mat;
        if (temp == target)return true;
        for (int k = 0; k < 3; k++) {
            temp = rotate90(temp);
            if (temp == target)return true;
        }
        return false;

    }

    vector<vector<int>>  rotate90(vector<vector<int>>& mat) {
        //vector<vector<int>> ret =
        int n = mat.size();
        vector<vector<int>> ret(n, vector<int>(n, 0));//初始化一个m行n列的元素值全为0的二维数组
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret[j][n-1-i] = mat[i][j];
            }
        }
        return ret;
    }
};
