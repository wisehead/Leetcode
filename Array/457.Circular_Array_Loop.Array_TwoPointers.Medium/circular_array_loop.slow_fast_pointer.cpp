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
    /*
    Just think it as finding a loop in Linkedlist, except that loops with only 1 element do not count. 
    Use a slow and fast pointer, slow pointer moves 1 step a time while fast pointer moves 2 steps a time. 
    If there is a loop (fast == slow), we return true, else if we meet element with different directions, 
    then the search fail, we set all elements along the way to 0. Because 0 is fail for sure so when later 
    search meet 0 we know the search will fail.
     */
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                continue;
            }
            // slow/fast pointer
            int j = i, k = getIndex(i, nums);
            while (nums[k] * nums[i] > 0 && nums[getIndex(k, nums)] * nums[i] > 0) {
                if (j == k) {
                    // check for loop with only one element
                    if (j == getIndex(j, nums)) {
                        break;
                    }
                    return true;
                }
                j = getIndex(j, nums);
                k = getIndex(getIndex(k, nums), nums);
            }
            // loop not found, set all element along the way to 0
            j = i;
            int val = nums[i];
            while (nums[j] * val > 0) {
                int next = getIndex(j, nums);
                nums[j] = 0;
                j = next;
            }
        }
        return false;
    }

    int getIndex(int i, vector<int>& nums) {
        int n = nums.size();
        return i + nums[i] >= 0? (i + nums[i]) % n: n + ((i + nums[i]) % n);
    }
};
int main()
{}
