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
    bool f(vector<int>& nums, int n) {
        //cout<<"enter:"<<n<<endl;
		bool ret = false;
        if (n == 0)
        {
            if (nums.size() == 1)
                return true;
            if (n == 0 && nums[0] > 0) 
            {
                //cout<<"exit:"<<n<<endl;
                return true;
            }
        }
		for (int i = 1; i <= n; i++)
		{
            //cout<<"i:"<<i<<"nums["<<n-i<<"]"<<nums[n-i]<<endl;
			if (nums[n-i] >= i) 
				ret = f(nums, n-i);
			if (ret)
            {
                return ret;
                //cout<<"exit:"<<n<<endl;
            }
		}
        //cout<<"exit:"<<n<<endl;
		return ret;
	}
    bool canJump(vector<int>& nums) {
		return f(nums, nums.size()-1);
    }
};
int main()
{}
