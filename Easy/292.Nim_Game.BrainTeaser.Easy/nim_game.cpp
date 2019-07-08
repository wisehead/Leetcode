/*******************************************************************************
 *      file name: nim_game.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/06- 1:01                                    
 *  modified time: 18/01/06- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
		if (n < 4)
			return true;
		if (n % 4 == 0)
			return false;
		return true;
    }
};
int main()
{}
