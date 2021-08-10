/*******************************************************************************
 *      file name: reach_a_number.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/19-19:11:58                              
 *  modified time: 2018/10/19-19:11:58                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) target = 0 - target;
		int steps = 1, x = 0;
		int count = 0;
		for (int i = 1; x < target; i++, steps++)
		{
			x += steps;
			//cout<<"i:"<<i<<"	steps:"<<steps<<"	x:"<<x<<endl;
			if (x == target)
			{
				count = i;
				break;
			}
			if (x > target)
			{
				x -= steps;
				count = (i-1) + 2*(target - x);
				break;
			}
		}
		return count;
    }
};
int main()
{
	Solution sol;
	//int ret = sol.reachNumber(3);
	//int ret = sol.reachNumber(2);
	int ret = sol.reachNumber(1);
	cout<<"ret:"<<ret<<endl;
}
