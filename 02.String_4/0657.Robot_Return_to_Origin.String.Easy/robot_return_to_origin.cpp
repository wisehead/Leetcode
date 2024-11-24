/*******************************************************************************
 *      file name: robot_return_to_origin.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/08-16:34:21                              
 *  modified time: 2018/09/08-16:34:21                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
		map<char, int> mm;
		mm['R'] = 0;
		mm['L'] = 0;
		mm['U'] = 0;
		mm['D'] = 0;
		int len = moves.length();
		for (int i=0; i<len; i++)
		{
			mm[moves[i]]++;
		}
		int left_right = mm['R'] - mm['L'];
		int up_down = mm['U'] - mm['D'];
		return (left_right == 0) && (up_down == 0);
    }
};
int main()
{}
