/*******************************************************************************
 *      file name: power_of_2.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/25-12:12                                    
 *  modified time: 17/12/25-12:12                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
		int x = n;
        if (x <= 0)
            return 0; 
		while (x > 1)
		{
			if(x % 2 == 1)
				return false;
			x = x/2;
		}
		return true;
    }
};
int main()
{
	Solution sol;
	int ret = false;
	int n = 0;
	n = 8;
	ret = sol.isPowerOfTwo(n);
	cout<<"n is:"<<n<<"	ret :"<<ret<<endl;
	n = 9;
	ret = sol.isPowerOfTwo(n);
	cout<<"n is:"<<n<<"	ret :"<<ret<<endl;
	n = -8;
	ret = sol.isPowerOfTwo(n);
	cout<<"n is:"<<n<<"	ret :"<<ret<<endl;
}
