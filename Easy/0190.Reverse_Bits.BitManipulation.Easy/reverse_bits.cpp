/*******************************************************************************
 *      file name: reverse_bits.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/04-12:12                                    
 *  modified time: 17/12/04-12:12                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t mask = 1;
		uint32_t mask_reverse = 1;
		uint32_t ret = n;
		for (int i=0; i<32; i++)
		{
			mask = 1<<i;
			//mask_reverse =2147483648>>i;
			mask_reverse = 0x80000000>>i;
			cout<<"mask:"<<mask<<endl;
			cout<<"mask_reverse:"<<mask_reverse<<endl;
			bool x = n & mask;
			bool y = n & mask_reverse;
			if ((int)x ^ (int)y)
			{
				ret = ret ^ mask;
			}
		}
		return ret;
    }
};

int main()
{
	Solution sol;
	uint32_t reverse = 0;
	reverse = sol.reverseBits(1);
	cout<<"reverse is:"<<reverse<<endl;
}
