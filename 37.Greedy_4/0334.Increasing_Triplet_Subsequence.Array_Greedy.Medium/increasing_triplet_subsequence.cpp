/*******************************************************************************
 *      file name: increasing_triplet_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/04-15:25:49                              
 *  modified time: 2021/12/04-15:25:49                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max2) {
                if (max2 == INT_MIN) {
                    max2 = nums[i];
                } else if (max1 == INT_MIN) {
                    max1 = max2;
                    max2 = nums[i];
                } else
                    return true;
            } else {
                if (nums[i] > max1) 
                    max2 = nums[i];
                else 
                    max1 = nums[i];
            }
            //cout<<"i:"<<i<<",max1:"<<max1<<",max2:"<<max2<<endl;
        }
        return false;
    }
 
};
int main()
{}
