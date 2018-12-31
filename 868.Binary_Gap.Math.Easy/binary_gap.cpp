/*******************************************************************************
 *      file name: binary_gap.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/31-21:54:54                              
 *  modified time: 2018/12/31-21:54:54                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int binaryGap(int N) {
		int max_zeros = 0;
		int i = 0;
		while (i<32)
		{
			int mask = 1<<i;
			if (N & mask)
				break;
			i++;
		}
		int j = 31;
		while (j>=0)
		{
			int mask = 1<<j;
			if (N & mask)
				break;
			j--;
		}
		bool start_zero_flag = false;
		int count = 0;
		cout<<"i:"<<i<<"	j:"<<j<<endl;
		int orig_delta = j - i;
		while(i<=j)
		{
			int mask = 1<<i;
			if(!(N & mask))
			{
				if(!start_zero_flag) start_zero_flag = true;
				count++;
				if (count > max_zeros) max_zeros = count;
			}
			else
			{
				start_zero_flag = false;
				count=0;
			}
			i++;
		}
		cout<<"max_zeros:"<<max_zeros<<endl;
		if (max_zeros == 0)
		{
			if (orig_delta > 0) return 1;
			return 0;
		}
		return max_zeros + 1;
	}
};
int main()
{
	Solution sol;
	int ret = sol.binaryGap(6);
	cout<<"ret:"<<ret<<endl;
}
