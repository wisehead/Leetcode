/*******************************************************************************
 *      file name: num_of_1_bits.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/04-12:12                                    
 *  modified time: 17/12/04-12:12                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
		uint32_t mask = 0;
		int count = 0;
		for (int i=0; i<32; i++)
		{
			mask = 1<<i;
			if (n & mask)
				count++;
		}
		return count;
    }
};
int main()
{}
