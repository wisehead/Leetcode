/*******************************************************************************
 *      file name: maximum_product_of_two_elements.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/04-07:36:13                              
 *  modified time: 2021/08/04-07:36:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //int max1 = (nums[0]-1)*(nums[1]-1);
        int max2 = (nums[n-1]-1)*(nums[n-2]-1);
        //return max(max1,max2);
        return max2;
    }
};
int main()
{}
