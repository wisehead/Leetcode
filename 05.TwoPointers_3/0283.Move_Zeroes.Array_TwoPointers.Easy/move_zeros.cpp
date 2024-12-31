/*******************************************************************************
 *      file name: move_zeros.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/04- 1:01                                    
 *  modified time: 18/01/04- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int size = nums.size();
		int count = 0;
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); )
		{
			if (*it == 0)
			{
				count++;
				nums.erase(it);
			}
			else
				it++;
		}
		for (int i = 0; i < count; i++)
		{
			nums.push_back(0);
		}
    }
};
int main()
{}
