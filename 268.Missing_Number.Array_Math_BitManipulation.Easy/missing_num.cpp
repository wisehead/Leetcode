/*******************************************************************************
 *      file name: missing_num.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/02- 1:01                                    
 *  modified time: 18/01/02- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
		uint64_t n = nums.size();
		vector<int>::iterator it;
		int out = 0;
		int y = 0;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			out = out ^ *it;
		}
		if ( (n + 1) % 4 == 0)
		{
			y = out;
		}
		else if ((n+1) % 4 == 1)
		{
			if (out == n)
			{
				y = out;
			}
			else
			{
				y = out ^ n;
			}
		}
		else if ((n+1) % 4 == 2)
		{
			y = out ^ 1;
		}
		else// (n+1)%4 == 3
		{
			if (out == 1)
				y = n;
			else
				y = out ^ n ^ 1;
		}
		return y;
    }
};
int main()
{
	int array[] = {9,6,4,2,3,5,7,0,1};
	vector<int> vec(array, array+9);
	int ret = 0;
	Solution sol;
	ret = sol.missingNumber(vec);
	cout<<"ret is:"<<ret<<endl;
}
