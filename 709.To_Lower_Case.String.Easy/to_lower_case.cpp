/*******************************************************************************
 *      file name: to_lower_case.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/22-16:31:42                              
 *  modified time: 2018/09/22-16:31:42                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string toLowerCase(string str) {
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (str[i] <= 'Z' && str[i] >= 'A')
				str[i] += 32;
		}
		return str;
    }
};
int main()
{}
