/*******************************************************************************
 *      file name: longest_consecutive_sequence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/10-19:48:28                              
 *  modified time: 2021/08/10-19:48:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxv = INT_MIN;
        int cnt = 1;
        if (nums.size() == 0) cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            //cout<<"i:"<<i<<":"<<nums[i]<<endl;
            if (nums[i] == nums[i-1]+1) {
                cnt++;
            } else if (nums[i] == nums[i-1]) {
                //do nothing
            } else {
                maxv = max(maxv, cnt);
                cnt = 1;
            }     
        }
        return max(maxv, cnt);
    }
};
int main()
{}
