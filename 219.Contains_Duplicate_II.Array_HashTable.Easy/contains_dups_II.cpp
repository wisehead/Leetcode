/*******************************************************************************
 *      file name: contains_dups_II.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/24-12:12                                    
 *  modified time: 17/12/24-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		uint64_t size = nums.size();
		map<int,uint64_t>m;
		map<int,uint64_t>::iterator it_m;
		for (uint64_t i=0; i<size; i++)
		{
			int j = 0;
			it_m = m.find(nums[i]);
			if (it_m != m.end())
			{
				j = it_m->second;
				//int max = 0;
				//int min = nums[i];
				/*
				for(uint64_t x=j; x<i; x++)
				{
					if(nums[x] > max)
						max = nums[x];
					if (nums[x] < min)
						min = nums[x];
				}
				if (max - min <= k)
					return true;
					*/
				if (i - j <= k)
					return true;
				else
					m.erase(it_m);
			}
			m.insert(pair<int,uint64_t>(nums[i],i));
		}
		return false;
    }
};
int main()
{}
