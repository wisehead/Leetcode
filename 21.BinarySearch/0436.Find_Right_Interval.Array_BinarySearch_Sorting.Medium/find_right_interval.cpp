/*******************************************************************************
 *      file name: find_right_interval.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/04-16:05:04                              
 *  modified time: 2021/12/04-16:05:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int N = intervals.size();
        vector<vector<int>> vec(intervals);
        vector<int> res;
        for (int i = 0; i < N; i++) {
            vec[i].push_back(i);
        } 
        sort(vec.begin(), vec.end());
        for (auto v : intervals) {
            vector<int> vx(3,0);
            vx[0] = v[1];
            vx[1] = v[1];
            
            vector<vector<int>>::iterator it = lower_bound(vec.begin(), vec.end(), vx);
            if (it == vec.end()) res.push_back(-1);
            else {
                vector<int> temp = *it;
                res.push_back(temp[2]);
            }
        }
        
        return res;
    }
};
int main()
{}
