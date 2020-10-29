/*******************************************************************************
 *      file name: 1bit_and_2bit_characters.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/22-16:49:44                              
 *  modified time: 2018/09/22-16:49:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
		int len = bits.size();
		for (int i = 0; i < len; i++)
		{
			if (bits[i] == 1)
			{
				i++;
				if (i == len - 1)
					return false;
			}
			else
			{
				if (i == len - 1)
					return true;
			}
		}
		return true;
    }
};
int main()
{}
