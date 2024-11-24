/*******************************************************************************
 *      file name: nth_digit.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/08- 1:01                                    
 *  modified time: 18/01/08- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
		/*
		int max = 0x7FFFFFFF;
		vector<char> vec;
		//stringstream ss;
		int sum = 0;
		for (int i=1; i<max; i++)
		{
			stringstream ss;
			string str;
			ss<<i;
			ss>>str;
			for (int j=0; j<str.length(); j++)
			{
				vec.push_back(str[j]);
				if (++sum == n)
					return str[j] - 0x30;
				cout<<"i:"<<i<<"str["<<j<<"]:"<<str[j]<<"	sum:"<<sum<<endl;
			}
		}
		return -1;
		*/
		if (n <10)
			return n;
		uint64_t a[10] = {0}; 
		a[0] = 9 * (0+1)*pow(10,0);
		int i = 0;
		for (i=1; i<10; i++)
		{
			a[i] = 9 * (i+1)*pow(10,i) + a[i-1];
			cout<<"a["<<i<<"] is:"<<a[i]<<endl;
			if (a[i] >= n)
				break;
		}
		int xmod = (n - 1 - a[i-1]) % (i+1);
		int xdiv = (n - 1- a[i-1]) / (i+1);
		cout<<"n :"<<n<<"	i:"<<i<<"	xdiv:"<<xdiv<<"	xmod:"<<xmod<<"	the number is:"<<pow(10,i)+xdiv<<endl;
		stringstream ss;
		string str;
		ss<<((int)(pow(10,i))+xdiv);
		ss>>str;
		for (int j=0; j<str.length(); j++)
		{
			if (j == xmod)
				return str[j] - 0x30;
			//cout<<"i:"<<i<<"str["<<j<<"]:"<<str[j]<<"	sum:"<<sum<<endl;
		}

		return -1;
    }
};
int main()
{
	Solution sol;
	int n = 100000000;
	int ret = 0;
	ret = sol.findNthDigit(n); 
	cout<<"ret for "<<n<<" is:"<<ret<<endl;
}
