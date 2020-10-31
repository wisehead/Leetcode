/*******************************************************************************
 *      File Name: a.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/09/12-11:30                                    
 * Modified Time: 2017/09/12-11:30                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        int n = nums.size();
        unordered_map<int, int> ht;
        for (int i = 0; i < n; i++) {
            if (ht.count(target - nums[i])) {
                vec.push_back(i);
                vec.push_back(ht[target - nums[i]]);
            } else {
                ht[nums[i]] = i;
            }
        }

        return vec;
    }
};

int main(int argc, char* argv[])
{
    vector<int> input_vec;
    vector<int> ret_vec;
    input_vec.push_back(2);
    input_vec.push_back(4);
    input_vec.push_back(6);
    input_vec.push_back(8);
    input_vec.push_back(10);
    cout<<"size of input_vec:"<<input_vec.size()<<endl;
    for (int i=0; i< input_vec.size(); i++)
    {
        cout<<"the "<<i<<" elements is:"<<input_vec[i]<<endl;
    }
    int target = 12;
    Solution solution;
    ret_vec = solution.twoSum(input_vec, target);
    return 0;
}
