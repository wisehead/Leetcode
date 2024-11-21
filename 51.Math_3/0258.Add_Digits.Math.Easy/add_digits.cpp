/*******************************************************************************
 *      file name: add_digits.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/02- 1:01                                    
 *  modified time: 18/01/02- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
		map<int, int> m;
		m[0] = 9;
		m[1] = 1;
		m[2] = 2;
		m[3] = 3;
		m[4] = 4;
		m[5] = 5;
		m[6] = 6;
		m[7] = 7;
		m[8] = 8;
		int x = num % 9;
		return (m.find(x))->second;
    }
};
int main()
{
	Solution sol;
	int x = 38;
	int ret = sol.addDigits(x);
	cout<<"ret is:"<<ret<<endl;
}
