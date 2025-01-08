/*******************************************************************************
 *      file name: maximum_area_rectangle_with_point_constraints_I.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/08- 1:01                                    
 * modified time: 25/01/08- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool hit(vector<vector<int>>& points, int i, int j, int m, int n, int r1, int r2) {
        for (int k = i+1; k < n; k++) {
            if (k == j || k == m) continue;
            if (points[k][1] >= r1 && points[k][1] <= r2)
                return true;
        }
        return false;
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int max_s = -1;
        vector<int> records;
        sort(points.begin(), points.end());
        for (int i = 0; i < points.size()-3; i++) {
            int j = i+1;
            if (points[j][0] != points[i][0]) continue;
            int m = j+1;
            while (m < points.size() && points[m][0] == points[i][0] ) m++;
            for (;m < points.size()-1; m++) {
                if (points[m][1] != points[i][1]) continue;
                int n = m + 1;
                if (points[n][0] != points[m][0]) continue;
                if (points[n][1] != points[j][1]) continue;
                int c1 = points[i][0];
                int c2 = points[n][0];
                int r1 = points[i][1];
                int r2 = points[n][1];
                if (!hit(points, i, j, m, n, r1, r2)) {
                    int s = (r2-r1)*(c2-c1);
                    if (s > max_s) {
                        max_s = s;
                    }
                }
            }
        }
        return max_s;
    }
};
