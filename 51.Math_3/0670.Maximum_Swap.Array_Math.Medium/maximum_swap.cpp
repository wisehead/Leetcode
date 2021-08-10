/*******************************************************************************
 *      file name: maximum_swap.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/13-14:14:20                              
 *  modified time: 2019/05/13-14:14:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
		int tmp = num;
		vector<int> vec;
		while (tmp)
		{
			int x = tmp % 10;
			vec.push_back(x);
			tmp = tmp/10;
		}
		reverse(vec.begin(), vec.end());
		int n = vec.size();
		int i = 0;
		for (;i < n-1; i++)
		{
			if (vec[i+1] > vec[i]) break;
		}
		int maxx = -1;
		int pos = 0;
		for (int j=i+1; j < n; j++)
		{
			if (vec[j] >= maxx)
			{
				maxx = vec[j];
				pos = j;
			}
		}
		//	maxx = max(vec[j], maxx);

		for (int j = 0; j <= i; j++)
		{
			if (maxx > vec[j])
			{
				swap(vec[j], vec[pos]);
				break;
			}
		}

		int sum = 0;
		for (int k = 0; k < n; k++)
		{
			sum = sum*10 + vec[k];
		}
		return sum;

    }
};
int main()
{}
