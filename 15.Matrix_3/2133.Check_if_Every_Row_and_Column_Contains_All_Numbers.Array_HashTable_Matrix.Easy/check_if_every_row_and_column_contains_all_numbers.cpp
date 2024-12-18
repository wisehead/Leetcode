/*******************************************************************************
 *      file name: check_if_every_row_and_column_contains_all_numbers.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/18-12:12                                    
 * modified time: 24/12/18-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = 0; j < n; j++) {
                s.insert(matrix[i][j]);
            }
            if (s.size() < n) return false;
        }
        for (int j = 0; j < n; j++) {
            set<int> s;
            for (int i = 0; i < n; i++) {
                s.insert(matrix[i][j]);
            }
            if (s.size() < n) return false;
        }
        return true;
    }
};
