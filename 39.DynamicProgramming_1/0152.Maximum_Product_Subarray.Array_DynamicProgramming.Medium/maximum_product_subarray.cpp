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
		vector<int> vec(nums);
		int size = nums.size();
		int maxv = INT_MIN;
		for (int i = 0; i < size; i++)
		{
			if (vec[i] > maxv)
				maxv = vec[i];
		}
		for (int i = 1; i < size; i++)
		{
			for (int j = size - 1; j >= i; j--)
			{
				vec[j] = vec[j-1]*nums[j];
                //cout<<"i:"<<i<<"    j:"<<j<<"vec[j]"<<vec[j]<<endl;
				if (vec[j] > maxv)
					maxv = vec[j];
			}
		}
		return maxv;
    }
};
int main()
{}
