/*******************************************************************************
 *      file name: power_of_4.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/06- 1:01                                    
 *  modified time: 18/01/06- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int num) {
		uint64_t mask1 = 0x00000001;
		uint64_t mask2 = 0x00000004;
		uint64_t mask3 = 0x00000010;
		uint64_t mask4 = 0x00000040;
		uint64_t mask5 = 0x00000100;
		uint64_t mask6 = 0x00000400;
		uint64_t mask7 = 0x00001000;
		uint64_t mask8 = 0x00004000;
		uint64_t mask9 = 0x00010000;
		uint64_t mask10 = 0x00040000;
		uint64_t mask11 = 0x00100000;
		uint64_t mask12 = 0x00400000;
		uint64_t mask13 = 0x01000000;
		uint64_t mask14 = 0x04000000;
		uint64_t mask15 = 0x10000000;
		uint64_t mask16 = 0x40000000;
		return !(num ^ mask1) 
			   || !(num ^ mask2) 
			   || !(num ^ mask3) 
			   || !(num ^ mask4) 
			   || !(num ^ mask5) 
			   || !(num ^ mask6) 
			   || !(num ^ mask7) 
			   || !(num ^ mask8) 
			   || !(num ^ mask9) 
			   || !(num ^ mask10) 
			   || !(num ^ mask11) 
			   || !(num ^ mask12) 
			   || !(num ^ mask13) 
			   || !(num ^ mask14) 
			   || !(num ^ mask15) 
			   || !(num ^ mask16);
    }
};
int main()
{}
