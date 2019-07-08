/*******************************************************************************
 *      file name: num_complement.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/15-11:58:32                              
 *  modified time: 2018/08/15-11:58:32                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
		int mask = 1;
		int i = 0;
		for (i = 31; i > -1 ; i--)
		{
			mask = 1<<i;
			if ((num & mask) != 0)
				break;
			/*
			if (leading_zero && (num & mask) != 0)
			{
				leading_zero = false;
			}
			*/
		}
		cout<<"i is:"<<i<<endl;
		int mask_xor = (1<<(i+1)) - 1;
		cout<<"mask_xor is:"<<mask_xor<<endl;
		return (num^mask_xor);
    }
};
int main()
{
	Solution sol;
	int ret = 0;
	int input = 0;
	//input = 5;
	input = 1;
	ret = sol.findComplement(input);
	cout<<"input :"<<input<<"	result:"<<ret<<endl;
}
