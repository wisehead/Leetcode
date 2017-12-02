/*******************************************************************************
 *      file name: factorial_trailing_zeros.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/29-11:11                                    
 *  modified time: 17/11/29-11:11                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
		int count = 0;
		int temp = 0;
		for (int i=0; i<=n; i=i+5)
		{
			temp = i;
			while (temp!= 0 && temp % 5 == 0)
			{
				count++;
				temp = temp/5;
			}
		}
		return count;
    }
};
int main()
{
	Solution sol;
	int out = 0;
	int n= 0;
	//for (;n<=4294967296 && n>0; n = n+5)
	for (;n<=67296 && n>=0; n = n+5)
	{
		out = sol.trailingZeroes(n);
		cout<<"zero count for "<<n<<" is:"<<out<<endl;
	}
}
