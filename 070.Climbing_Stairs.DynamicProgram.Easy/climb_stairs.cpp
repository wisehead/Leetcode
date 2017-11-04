/*******************************************************************************
 *      file name: climb_stairs.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/04-11:11                                    
 * modified time: 17/11/04-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
		vector<unsigned long long> vec;
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;
		/*
		return climbStairs(n-1) + climbStairs(n-2);
		*/
		vec.push_back(1L);
		vec.push_back(1L);
		for (int i=2; i<=n; i++)
		{
			vec.push_back(vec[i-1] + vec[i-2]);
		}
		return vec[n];
    }
};
int main()
{
	Solution sol;
	int x = 0;
	x = sol.climbStairs(2);
	cout<<"solutions for 2 is:"<<x<<endl;
	x = sol.climbStairs(3);
	cout<<"solutions for 3 is:"<<x<<endl;
	x = sol.climbStairs(5);
	cout<<"solutions for 5 is:"<<x<<endl;
	x = sol.climbStairs(10);
	cout<<"solutions for 10 is:"<<x<<endl;
	x = sol.climbStairs(20);
	cout<<"solutions for 20 is:"<<x<<endl;
	x = sol.climbStairs(50);
	cout<<"solutions for 50 is:"<<x<<endl;
}
