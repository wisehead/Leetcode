/*******************************************************************************
 *      file name: sum_of_all_subset_XOR_totals.bit_combine.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/06-10:45:11                              
 *  modified time: 2021/08/06-10:45:11                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Approach 2: O(n * 2 ^ n)
Since we only have 12 numbers, we can represent all combinations using a bitmask: [1 << 0.... 1 << n):

Iterate through all bitmask values;
Go through array and do XOR numbers at positions indicated by the bitmask.
*/
class Solution {
public:   
	int subsetXORSum(vector<int>& nums) {
		int res = 0;
		for (auto i = 1; i < (1 << nums.size()); ++i) {
			int total = 0;
			for (auto j = 0; j < nums.size(); ++j)
				if (i & (1 << j))
					total ^= nums[j];
			res += total;
		}
		return res;
	}
};
int main()
{}
