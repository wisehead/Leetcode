/*******************************************************************************
 *      file name: jump_game.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/11-11:25:20                              
 *  modified time: 2019/03/11-11:25:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums)
	{
		int i=0;
        const int n=nums.size();
        for(int step=0;i<n && i<=step;++i)
        {
            step=max(step,nums[i]+i);
            if(step>=n-1) return true;
        }
        return n==i;
	}
};
int main()
{}
