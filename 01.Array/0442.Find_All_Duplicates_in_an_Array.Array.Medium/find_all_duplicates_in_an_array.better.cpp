/*******************************************************************************
 *      file name: find_all_duplicates_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/19-09:34:15                              
 *  modified time: 2019/04/19-09:34:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
        int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			while (nums[i] != i+1 && nums[i] != -1 && nums[i] != 0)
			{
				int pos = nums[i];
				if (nums[i] == nums[pos-1])
				{
					nums[pos-1] = -1;
					nums[i] = 0;
					break;
				}
				swap(nums[i], nums[pos-1]);
			}
		}
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) res.push_back(i+1);
        }
        return res;
    }
};
int main()
{}
