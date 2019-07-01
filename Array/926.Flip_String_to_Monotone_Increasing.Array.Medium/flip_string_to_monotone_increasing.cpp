/*******************************************************************************
 *      file name: flip_string_to_monotone_increasing.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/01-10:08:06                              
 *  modified time: 2019/07/01-10:08:06                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string S) {
		int n = S.length();
		int r_zeros = 0, l_ones = 0;
		int sum = 0, minsum = 0;
		for (auto e: S)
		{
			if (e == '0')
				r_zeros++;
		}
        sum = l_ones + r_zeros;
        minsum = sum;
		
		for (int i = 0; i < n; i++)
		{
			if (S[i] == '0')
				r_zeros--;
			else
				l_ones++;
			sum = l_ones + r_zeros;
            //cout<<"l_ones:"<<l_ones<<"  r_zeros:"<<r_zeros<<"   sum:"<<sum<<endl;
			minsum = min(minsum, sum);
		}
		return minsum;
    }
};
int main()
{}
