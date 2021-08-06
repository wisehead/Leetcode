/*******************************************************************************
 *      file name: sum_of_2_integers.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/07- 1:01                                    
 *  modified time: 18/01/07- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	//int add(int a, int b, int &carry_flag)
    int getSum(int a, int b) {
		int mask = 0x01;
		int ret = 0;
		bool flag = false;
		for (int i=0; i<32; i++)
		{
			mask = 1<<i;
			int bita = a & mask;
			int bitb = b & mask;
			int bitr= 0;
			if (flag == false)
			{
				bitr = bita ^ bitb;
				//cout<<"flag=0 bita:"<<bita<<"	bitb:"<<bitb<<"	bitr:"<<bitr<<endl;
				if (bita & bitb)
				{
					flag = true;
				}
			}
			else
			{
				flag = false;
				bitr = bita ^ bitb ^ mask;
				//cout<<"flag=1 bita:"<<bita<<"	bitb:"<<bitb<<"	bitr:"<<bitr<<endl;
				if (bita | bitb)
				{
					flag = true;
				}
			}
			ret = ret | bitr;
			//cout<<"bitr:"<<bitr<<"	flag:"<<flag<<"	ret:"<<ret<<endl;
		}
		return ret;
    }
};
int main()
{
	Solution sol;
	int ret = 0;
	//int a = 3;
	//int b = 5;
	int a = 2147483646;
	int b = 100;
	ret = sol.getSum(a, b);
	cout<<"ret for "<<a<<" and "<<b<<" is:"<<ret<<endl;
}
