/*******************************************************************************
 *      file name: count_primes.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/22-12:12                                    
 *  modified time: 17/12/22-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
		//int my_sqrt = sqrt(n);
		int count = 0;
		for (int i=1; i < n; i++)
		{
			int j = 2;
			int s = sqrt(i);
			//cout<<"sqrt for "<<i<<"is:"<<s<<endl;
			for (; j< s+2 &&j<i; j++)
			{
				if (i % j == 0)
					break;
			}
			cout<<"i:"<<i<<"	j:"<<j<<"	s:"<<s<<endl;
			if (j == s+2 || i==2)
			{
				count++;
				cout<<"prime is:"<<i<<"		"<<endl;;
			}
		}
		cout<<endl;
		return count;
    }
};
int main()
{
	Solution sol;
	int ret = 0;
	//ret = sol.countPrimes(2);
	//cout<<"count for 2:"<<ret<<endl;
	//ret = sol.countPrimes(3);
	//cout<<"count for 3:"<<ret<<endl;
	//ret = sol.countPrimes(10);
	//cout<<"count for 10:"<<ret<<endl;
	ret = sol.countPrimes(20);
	cout<<"count for 20:"<<ret<<endl;
}
