/*******************************************************************************
 *      file name: sell_stock.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/19-11:11                                    
 * modified time: 17/11/19-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (size == 0)
			return 0;
		int min = prices[0];
		int current_delta = 0;
		vector<int>::iterator it;
		for (it = prices.begin(); it != prices.end(); it++)
		{
			if (*it < min)
				min = *it;
			if (*it - min > current_delta)
				current_delta =  *it - min;
		}
		return current_delta;
    }
};
int main()
{}
