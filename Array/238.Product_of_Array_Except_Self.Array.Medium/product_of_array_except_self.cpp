/*******************************************************************************
 *      file name: product_of_array_except_self.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/15-09:45:19                              
 *  modified time: 2019/04/15-09:45:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int prod = 1, zeros = 0;
		for (auto e: nums)
        {
            if (!e) 
                zeros++;
            else
    			prod *= e;
        }
		for (auto &e: nums)
		{
            if (e)//not zero
            {
                if (zeros)
                {
                    e = 0;
                }
                else
    			    e = prod/e;
            }
            else//e is zero
            {
                if (zeros > 1) 
                    e = 0;
                else
                    e = prod;
            }
		}
		return nums;
    }
};
int main()
{}
