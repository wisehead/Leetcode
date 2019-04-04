/*******************************************************************************
 *      file name: maximum_product_subarray.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/03-19:48:52                              
 *  modified time: 2019/04/03-19:48:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    	int frontProduct = 1;
    	int backProduct = 1;
  		int ans = INT_MIN;
  		for (int i = 0; i < n; ++i) {
  			frontProduct *= nums[i];
  			backProduct *= nums[n - i - 1];
  			ans = max(ans,max(frontProduct,backProduct));
  		    frontProduct = frontProduct == 0 ? 1 : frontProduct;
  		    backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};
int main()
{}
