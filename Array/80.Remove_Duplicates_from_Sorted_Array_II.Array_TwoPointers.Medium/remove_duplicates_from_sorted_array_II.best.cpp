/*******************************************************************************
 *      file name: remove_duplicates_from_sorted_array_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/27-09:51:59                              
 *  modified time: 2019/03/27-09:51:59                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
	    int i = 0;
	    for (int n : nums)
	        if (i < 2 || n > nums[i-2])
	            nums[i++] = n;
	    return i;
	}
};
int main()
{}
