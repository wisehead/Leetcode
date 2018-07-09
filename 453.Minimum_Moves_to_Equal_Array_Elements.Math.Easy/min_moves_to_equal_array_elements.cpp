/*******************************************************************************
 *      file name: min_moves_to_equal_array_elements.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/09-11:17:52                              
 *  modified time: 2018/07/09-11:17:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
		vector<int>::iterator it;
		if (nums.size() == 0)
			return 0;
		int min = nums[0];
		int delta = 0;
		map<int, int> m;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			if (*it < min)
				min = *it;
		}
		for (it = nums.begin(); it != nums.end(); it++)
		{
			delta += (*it - min);
		}
		return delta;
    }
};
int main()
{}
