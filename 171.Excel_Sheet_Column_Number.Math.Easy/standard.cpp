/*******************************************************************************
 *      file name: standard.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/29-11:11                                    
 *  modified time: 17/11/29-11:11                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
		int result = 0;
		for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
		return result;
    }
};
int main()
{}
