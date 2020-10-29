/*******************************************************************************
 *      file name: pascal_triangle.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/17-11:11                                    
 * modified time: 17/11/17-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<int> vec_ping;
		vector<int> vec_pong;
		vector<vector<int> > vec;
		//queue<vector<int> > my_queue;
		vec_ping.push_back(1);
		if (numRows <= 0)
			return vec;
		vec.push_back(vec_ping);
		//my_queue.push(vec_ping);
		if (numRows == 1)
			return vec;
		
		int count = 1;
		while (count < numRows)
		{
			vec_pong.clear();
			for (int i = 0; i<=vec_ping.size(); i++)
			{
				if (i == 0 || i == vec_ping.size())
					vec_pong.push_back(1);
				else
					vec_pong.push_back(vec_ping[i] + vec_ping[i-1]);
			}
			//my_queue.push(vec_pong);
			vec.push_back(vec_pong);
			vec_ping.clear();
			vec_ping.assign(vec_pong.begin(), vec_pong.end());
			count++;
		}
		return vec;
    }
};

int main()
{}
