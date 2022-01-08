/*******************************************************************************
 *      file name: special_array_with_X_elements_greater_than_or_euual_X.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/08-10:53:27                              
 *  modified time: 2022/01/08-10:53:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int i = 0;
        for (int x = 0; x <= N; x++) {  
            for (; i < N; i++) {
                if (nums[i] >= x) break;
            }
            if (N-i == x) return x;
        }
        return -1;
    }
};
int main()
{}
