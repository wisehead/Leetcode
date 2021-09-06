/*******************************************************************************
 *      file name: create_target_array_in_the_given_order.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/06-10:43:29                              
 *  modified time: 2021/09/06-10:43:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        int N = nums.size();
        for(int i = 0; i < N; i++) {
            target.insert(target.begin()+index[i], nums[i]);
        }
        return target;
    }
};
int main()
{}
