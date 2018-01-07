/*******************************************************************************
 *      file name: valid_perfect_square.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/07- 1:01                                    
 *  modified time: 18/01/07- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
		if (num < 1) return false;
		if (num == 1) return true;
		int left = 1, right = num, mid = 0;
		int div = num;
		while (left < right)
		{
			mid = (left + right) / 2 ;
			//cout<<"mid is:"<<mid<<endl;
			div = num / mid;
			if (mid == div) 
			{
				if (num % mid == 0)
					return true;
				break;
			}
			if (div > mid)
			{
				left = mid + 1;
				//cout<<"left is:"<<left<<endl;
			}
			else
			{
				right = mid;
				//cout<<"right is:"<<right<<endl;
			}
		}
		return false;
    }
};
int main()
{
	Solution sol;
	bool ret = false;
	int n = 0;
	for (;n <= 100; n++)
	{
		ret = sol.isPerfectSquare(n);
		cout<<"ret for "<<n<<" is:"<<ret<<endl;
	}
	/*
	n = 1;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	n = 2;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	n = 3;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	n = 4;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	n = 5;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	n = 6;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	*/
	/*
	n = 9;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	n = 2147483647;
	ret = sol.isPerfectSquare(n);
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
	*/
}
