/*******************************************************************************
 *      file name: complement_of_base_10_integer.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/16-18:36:35                              
 *  modified time: 2020/09/16-18:36:35                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int N) {
        int x = N;
		int count = 1;
        if (N == 0) return 1;
		while (x > 0) {
			x = x/2;
			count *= 2;
		}
		return count - 1 - N;
    }
};
int main()
{}
