/*******************************************************************************
 *      file name: sqrt.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/04-11:11                                    
 * modified time: 17/11/04-11:11                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
		if (x < 0)
			return -1;
		int low = 0;
		int high = x;
		long long mid = (low + high)/2;
        while (low < high)
        {
            mid = (low + high)/2;
            if (mid*mid == x)
            {
                return mid;
            }
            else if(mid*mid > x)
            {
                if (high == mid)
                {
					if ((mid-1)*(mid-1) == x)
						return mid-1;
                    break;
                }
                else
                    high = mid;
            }
            else//mid*mid < x
            {
                if (low == mid)
				{
					if ((mid+1)*(mid+1) == x)
						return mid+1;
                    break;
				}
                else
                    low = mid;
            }
        }
        return mid;
    }
};
int main()
{
	Solution sol;
	int sqrt = 0;
/*
	sqrt = sol.mySqrt(4);
	cout <<"sqrt for 4 is:"<<sqrt<<endl;
	sqrt = sol.mySqrt(0);
	cout <<"sqrt for 0 is:"<<sqrt<<endl;
	sqrt = sol.mySqrt(1);
	cout <<"sqrt for 1 is:"<<sqrt<<endl;
	sqrt = sol.mySqrt(3);
	cout <<"sqrt for 3 is:"<<sqrt<<endl;
	sqrt = sol.mySqrt(5);
	cout <<"sqrt for 5 is:"<<sqrt<<endl;
	sqrt = sol.mySqrt(8);
	cout <<"sqrt for 8 is:"<<sqrt<<endl;
	sqrt = sol.mySqrt(9);
	cout <<"sqrt for 9 is:"<<sqrt<<endl;
	sqrt = sol.mySqrt(10);
	cout <<"sqrt for 10 is:"<<sqrt<<endl;
*/
	sqrt = sol.mySqrt(2147395599);
	cout <<"sqrt for 2147395599 is:"<<sqrt<<endl;
	
}
