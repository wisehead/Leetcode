/*******************************************************************************
 *      file name: running_sum_of_1d_array.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/11-09:14:12                              
 *  modified time: 2021/08/11-09:14:12                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int sum = 0;
        for (auto e : nums) {
            sum += e;
            res.push_back(sum);
        }
        return res;
    }
};
int main()
{}
