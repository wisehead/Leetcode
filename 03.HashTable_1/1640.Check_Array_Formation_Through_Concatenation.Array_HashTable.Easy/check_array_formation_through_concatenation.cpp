/*******************************************************************************
 *      file name: check_array_formation_through_concatenation.cpp                                               
 *         author: hui chen. (c) 22                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 22/08/01- 8:08                                    
 * modified time: 22/08/01- 8:08                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for (auto piece : pieces) {
            int N = piece.size();
            int start = piece[0];
            vector<int>::iterator it = find( arr.begin( ), arr.end( ), start);
            if (it == arr.end()) return false;
            for (int i = 0; i < N; i++, it++) {
                if (piece[i] != *it) return false;
            }
        }
        return true;
    }
};
