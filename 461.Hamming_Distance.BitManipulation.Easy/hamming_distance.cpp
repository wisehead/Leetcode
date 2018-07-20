/*******************************************************************************
 *      file name: hamming_distance.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/20-21:02:36                              
 *  modified time: 2018/07/20-21:02:36                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
		int z = (x ^ y);
		int mask = 0;
		int count = 0;
		for (int i=0; i< 32; i++)
		{
			mask = 1 << i;
			if ((z & mask) != 0)
				count++;
		}
		return count;
    }
};
int main()
{}
