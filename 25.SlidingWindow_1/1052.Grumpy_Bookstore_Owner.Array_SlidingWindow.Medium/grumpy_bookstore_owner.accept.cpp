/*******************************************************************************
 *      file name: grumpy_bookstore_owner.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/16-21:02:44                              
 *  modified time: 2020/01/16-21:02:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int delta = 0, sum = 0;
		int n = customers.size();
		for (int i = 0; i < n - X + 1; i++)
		{
			int cnt = 0;
			for (int j = i; j < i+X; j++)
			{
				if (grumpy[j] == 1)
					cnt += customers[j];
			}
			delta = max(delta, cnt);
            //cout<<"i:"<<i<<"    cnt:"<<cnt<<endl;
		}

		for(int i = 0; i < n; i++)
		{
			if (grumpy[i] == 0)
				sum += customers[i];
		}
		sum += delta;
		return sum;
    }
};
int main()
{

//customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
}
