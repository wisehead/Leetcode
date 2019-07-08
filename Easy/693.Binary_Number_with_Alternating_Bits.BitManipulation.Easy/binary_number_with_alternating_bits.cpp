/*******************************************************************************
 *      file name: binary_number_with_alternating_bits.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/19-22:14:42                              
 *  modified time: 2018/09/19-22:14:42                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
		bool res = false;
		for (int i=0; i<32; i++)
		{
			int mask = 1<<i;
            if (n / mask < 1) break;
			bool temp = ((n & mask) != 0);
			if (i==0) {
				res = temp;
				continue;
			}
			if (temp == res) return false;
			res = temp;
		}
		return true;
    }
};
int main()
{}
