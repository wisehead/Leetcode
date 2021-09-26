/*******************************************************************************
 *      file name: rotate_array.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/04-12:12                                    
 *  modified time: 17/12/04-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size == 0)
			return;
		vector<int>::iterator it;
		for (int i=0; i<k; i++)
		{
			int temp = nums.back();
			nums.insert(nums.begin(), temp);
			nums.pop_back();
		}
    }
};

int main()
{}
