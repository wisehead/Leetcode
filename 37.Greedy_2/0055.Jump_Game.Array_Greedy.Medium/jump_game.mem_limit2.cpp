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
    bool quickCheck(vector<int>& nums, int c) {
        int pos = c;
        //int steps = nums[pos];
        while (nums[pos])
        {
            if (pos + nums[pos] >= nums.size() - 1) return true;
            pos += nums[pos];
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int size = nums.size();
		queue<int> q1;
		set<int> s1;
		if (nums[0] == 0 && size != 1)
			return false;
		q1.push(0);
		while (!q1.empty())
		{
			int x = q1.front();
            q1.pop();
            //cout<<"x:"<<x<<endl;
			if (s1.count(x)) continue;
			s1.insert(x);
			if (nums[x] > 0)
			{
				for (int i = nums[x]; i >= 0; i--)
				{
                    if (x+i >= size - 1) return true;
                    if (quickCheck(nums, x+i)) return true;
					q1.push(x+i);
					//s1.insert(x+i);
				}
			}
		}
		return (s1.count(nums.size() - 1));
    }
};
int main()
{}
