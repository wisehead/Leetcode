/*******************************************************************************
 *      file name: widest_vertical_area_between_two_points_containing_no_points.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/17- 9:09                                    
 * modified time: 24/09/17- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int max_space = 0;
        vector<int> vecx;
        set<int> ss;
        for (auto vec : points) {
            ss.insert(vec[0]);
        }
        std::copy(ss.begin(), ss.end(), std::back_inserter(vecx));
        sort(vecx.begin(), vecx.end());
        for (int i = 1; i < vecx.size(); i++) {
            int space = vecx[i] - vecx[i-1];
            if (space > max_space) {
                max_space = space;
            }
        }
        return max_space;
    }
};
