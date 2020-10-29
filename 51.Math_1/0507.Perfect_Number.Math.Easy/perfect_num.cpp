/*******************************************************************************
 *      file name: perfect_num.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/21-18:02:26                              
 *  modified time: 2018/08/21-18:02:26                              
 *******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;
		int count = 0;
		for (int i = 1; i <= sqrt(num); i++)
		{
			int mod = num % i;
			if (mod == 0)
            {
				count += i;
                int divisor = num / i;
                if (divisor != i && divisor != num)
                    count += divisor;
            }
		}
        //cout<<"count :"<<count<<endl;
		return (count == num);
    }
};
int main()
{}
