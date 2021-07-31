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
		int size = nums.size();
		if (size <= 1) return size;
		vector<int>::iterator it, it_last;
		int len = 1;
		for (it_last = nums.begin(), it = it_last + 1; it != nums.end(); it++)
		{
			if (*it == *it_last)
			{
				if (it != it_last + 1)
				{
					nums.erase(it);
					it--;
				}
				else
					len++;
			}
			else
			{
				it_last = it;
				len++;
			}
		}
		return len;
    }
};
int main()
{}
