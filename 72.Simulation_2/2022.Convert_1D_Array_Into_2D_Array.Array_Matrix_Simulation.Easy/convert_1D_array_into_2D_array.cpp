/*******************************************************************************
 *      file name: convert_1D_array_into_2D_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/25- 9:09                                    
 * modified time: 24/09/25- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<int> vec;
        vector<vector<int>> res;
        if (original.size() != m*n) return res;
        for (int j = 0; j < original.size(); j++) {
            if (j % n == 0 && j > 0) {
                res.push_back(vec);
                vec.clear();
            }
            vec.push_back(original[j]);
        }
        res.push_back(vec);
        return res;
    }
};
