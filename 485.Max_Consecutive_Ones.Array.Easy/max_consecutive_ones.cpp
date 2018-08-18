/*******************************************************************************
 *      file name: max_consecutive_ones.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/19-07:12:40                              
 *  modified time: 2018/08/19-07:12:40                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		vector<int>::iterator it;
		int count = 0;
		int max = 0;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			if(*it == 0) 
			{
				if (count > max)
					max = count;
				count = 0;
			}
			else
				count++;
		}
		if (count > max)
			max = count;        
		return max;
    }
};
int main()
{}
