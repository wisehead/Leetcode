/*******************************************************************************
 *      file name: queue_reconstruction_by_height.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/16-12:12                                    
 * modified time: 24/12/16-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(),comp);
        int n = people.size();
        for (auto p : people) {
            res.insert(res.begin()+p[1], p);
        }
        return res;
    }
};
