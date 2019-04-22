/*******************************************************************************
 *      file name: circular_array_loop.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/22-09:55:42                              
 *  modified time: 2019/04/22-09:55:42                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        bool loop = false;
        for (int i = 0; i < nums.size() && !loop; i++)
            if (nums[i]) {
                int j1 = i, j2 = i, dir = nums[i];
                do {
                    j1 = advanceBy(1, j1, nums, dir);
                    j2 = advanceBy(2, j2, nums, dir);
                } while (j1 >= 0 && j2 >= 0 && j1 != j2);
                
                if (j1 >= 0 && j2 >= 0 && j1 == j2) {
                    if (j1 == advanceBy(1, j1, nums, dir))
                        nums[j1] = 0;
                    else
                        loop = true;
                }
                
                nums[i] = 0;
            }
        return loop;
    }
    
    int advanceBy(int step, int j, vector<int>& nums, int dir) {
        int n = nums.size();
        for (; step > 0; step--) {
            j = (j + nums[j] + n) % n;
            if (nums[j] * dir <= 0)
                return -1;
        }
        return j;
    }
};
int main()
{}
