/*******************************************************************************
 *      file name: ugly_number.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/02- 1:01                                    
 *  modified time: 18/01/02- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isUgly(int num) {
		int x = num;
		if (x == 0) return false;
		while (x % 2 == 0)
		{
			x = x / 2;
		}
		while (x % 3 == 0)
		{
			x = x / 3;
		}
		while (x % 5 == 0)
		{
			x = x / 5;
		}
		if (x == 1)
			return true;
		return false;
    }
};
int main()
{
	Solution sol;
	bool ret = false;
	int x = 0;
	ret = sol.isUgly(x);
	cout<<"ret for "<<x<<" is:"<<ret<<endl;
	x = -1;
	ret = sol.isUgly(x);
	cout<<"ret for "<<x<<" is:"<<ret<<endl;
	x = -6;
	ret = sol.isUgly(x);
	cout<<"ret for "<<x<<" is:"<<ret<<endl;
	x = 8;
	ret = sol.isUgly(x);
	cout<<"ret for "<<x<<" is:"<<ret<<endl;
	x = 14;
	ret = sol.isUgly(x);
	cout<<"ret for "<<x<<" is:"<<ret<<endl;
}
