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
        vector<int> res;
        vector<int> vec(101,0);
        for (auto e : nums) {
            vec[e]++;
        }

        vector<int> count(101,0);
        for (int i = 1; i < vec.size(); i++) {
            count[i] = count[i-1] + vec[i-1];
        }

        for (auto e : nums) {
            //cout<<"e:"
            res.push_back(count[e]);
        }
        return res;
    }
};
int main()
{}
