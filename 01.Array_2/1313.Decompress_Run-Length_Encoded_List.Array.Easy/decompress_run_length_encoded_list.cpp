/*******************************************************************************
 *      file name: decompress_run_length_encoded_list.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/20-18:12:55                              
 *  modified time: 2020/01/20-18:12:55                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
		int n = nums.size();
		vector<int> res;
		for (int i = 0; i < n; i += 2)
		{
			int a = nums[i];
			int b = nums[i+1];
			res.insert(res.end(), a, b);
		}
		return res;
    }
};
int main()
{}
