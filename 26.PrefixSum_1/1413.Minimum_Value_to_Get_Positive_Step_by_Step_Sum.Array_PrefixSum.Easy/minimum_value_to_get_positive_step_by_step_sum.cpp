/*******************************************************************************
 *      file name: minimum_value_to_get_positive_step_by_step_sum.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/27-10:27:12                              
 *  modified time: 2021/09/27-10:27:12                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minv = 0;
        int sum = 0;
        for (auto e : nums) {
            sum += e;
            if (sum < minv) minv = sum;
        }
        return 1 - minv;
    }
};
int main()
{}
