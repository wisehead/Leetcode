/*******************************************************************************
 *      file name: how_many_numbers_are_smaller_than_the_current_number.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/11-09:37:40                              
 *  modified time: 2021/08/11-09:37:40                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec(nums.begin(), nums.end());
        vector<int> res;
        sort(vec.begin(), vec.end());
        unordered_map<int, int> mm;
        mm[vec[0]] = 0;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] != vec[i-1]) mm[vec[i]] = i;
        }
        
        for (auto e : nums) {
            res.push_back(mm[e]);
        }
        return res;
    }
};
int main()
{}
