/*******************************************************************************
 *      file name: minimum_absolute_difference.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/14-16:43:56                              
 *  modified time: 2020/11/14-16:43:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            int delta = arr[i+1] - arr[i];
            min_diff = min(min_diff, delta);
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i+1] - arr[i] == min_diff) {
                vector<int> vec = {arr[i], arr[i+1]};
                res.push_back(vec);
            }
        }
        return res;
    }
};
int main()
{}
