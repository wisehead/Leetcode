/*******************************************************************************
 *      file name: contains_dups.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/24-12:12                                    
 *  modified time: 17/12/24-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		uint64_t size = nums.size();
		set<int> s;
		set<int>::iterator it;
		for (uint64_t i=0; i<size; i++)
		{
			it = s.find(nums[i]);
			if (it != s.end())
				return true;
			s.insert(nums[i]);
		}
		return false;
    }
};
int main()
{}
