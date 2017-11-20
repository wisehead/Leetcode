/*******************************************************************************
 *      file name: buy_sell_stock2.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/20-11:11                                    
 * modified time: 17/11/20-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (size <= 1)
			return 0;
		int min = -1;
		int max = -1;
		int sum = 0;
		if (prices[1] >= prices[0])
		{
			min = prices[0];
			max = prices[1];
		}
		vector<int>::iterator it;
		for (it = prices.begin()+2; it != prices.end(); it++)
		{
			if (*it >= *(it-1))
			{
				if (*it > max)
					max = *it;
				if (*(it-2) >= *(it-1))
				{
					if ((min == -1) || *(it-1) < min)
						min = *(it-1);//buy
				}
			}
			else// *it < *(it-1) 
			{
				if ( *(it-2) <= *(it-1))
				{
					// do sell
					if (min != -1)
					{
						sum += (max - min);
						min = -1;
						max = -1;
					}
				}
			}
		}//end for
		// do sell
		if (min != -1)
		{
			sum += (max - min);
		}
		return sum;
    }
};

int main()
{}
