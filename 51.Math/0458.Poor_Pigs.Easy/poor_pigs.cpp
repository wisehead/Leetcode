/*******************************************************************************
 *      file name: poor_pigs.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/18-19:42:25                              
 *  modified time: 2018/07/18-19:42:25                              
 *******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int num = 0;
		for (int i = 0; i < buckets; i++)
		{
			//cout<<"i is:"<<i<<endl;
			//double x = log(buckets)/log(i);
			//cout<<"double x is:"<<x<<endl;
			//num = ceil(x);
			//cout<<"int num is:"<<num<<endl;
			num = minutesToTest/minutesToDie + 1;
			if (pow(num, i) >= buckets)
				return i;

		}
		return buckets;
    }
};
int main()
{
	Solution sol;
	//int n = sol.poorPigs(1000, 15, 60);
	int n = sol.poorPigs(1000, 12, 60);
	cout<<"result is:"<<n<<endl;
}
