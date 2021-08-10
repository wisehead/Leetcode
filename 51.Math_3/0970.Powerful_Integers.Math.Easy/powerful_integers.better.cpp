/*******************************************************************************
 *      file name: powerful_integers.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/12-09:54:19                              
 *  modified time: 2019/02/12-09:54:19                              
 *******************************************************************************/
#include <iostream>
#include <set>
#include <vector>
#include<cmath>

using namespace std;
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
		set<int> ss;
        int x_limit = bound;
        if (x != 1)
		    x_limit = log(bound)/log(x);
        
        int y_limit = bound;
        if (y != 1)
		    y_limit = log(bound)/log(y);
        
		for (int i = 0; i <= x_limit; i++)
		{
			for (int j=0; j <= y_limit; j++)
			{
				int n = pow(x,i) + pow(y,j);
				if (n <= bound)
					ss.insert(n);
			}
		}
		return vector<int>(ss.begin(), ss.end());
    }
};
int main()
{}
