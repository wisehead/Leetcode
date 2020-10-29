/*******************************************************************************
 *      file name: jump_game.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/11-11:25:20                              
 *  modified time: 2019/03/11-11:25:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
		queue<int> q1;
		set<int> s1;
		if (nums[0] == 0 && nums.size() != 1)
			return false;
		q1.push(0);
		while (!q1.empty())
		{
			int x = q1.front();
			if (s1.count(x)) continue;
			s1.insert(x);
			q1.pop();
			if (nums[x] > 0)
			{
				for (int i = 1; i <= nums[x]; i++)
				{
					q1.push(x+i);
					s1.insert(x+i);
				}
			}
		}
		return (s1.count(nums.size() - 1));
    }
};
int main()
{}
