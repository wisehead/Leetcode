/*******************************************************************************
 *      file name: lemonade_change.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/22-11:02:05                              
 *  modified time: 2018/12/22-11:02:05                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
		int sum_5 = 0;
		int sum_10 = 0;
		int size = bills.size();
		for (int i = 0; i < size; i++)
		{
			if (bills[i] == 5)
			{
				sum_5 += 5;
			}
			else if (bills[i] == 10)
			{
				if (sum_5 == 0)
					return false;
				sum_5 -= 5;
				sum_10 += 10;
			}
			else//20
			{
				if (sum_10 > 0)
				{
					sum_10 -= 10;
					if (sum_5 > 0)
						sum_5 -= 5;
					else
						return false;
				}
				else// == 0
				{
					if (sum_5 >= 15)
						sum_5 -= 15;
					else
						return false;
				}
			}

		}
		return true;
    }
};
int main()
{}
