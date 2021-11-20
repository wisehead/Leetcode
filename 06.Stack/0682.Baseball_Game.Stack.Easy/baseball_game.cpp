/*******************************************************************************
 *      file name: baseball_game.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/14-23:06:47                              
 *  modified time: 2018/09/14-23:06:47                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack> 
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
		int len = ops.size();
		stack<int> mystack; 
		int sum = 0;
		for (int i=0; i<len; i++)
		{
			if(ops[i] == "C")
			{
				int temp = mystack.top();
				mystack.pop();
				sum -= temp; 
			}
			else if (ops[i] == "D")
			{
				int temp = mystack.top();
				temp = temp*2;
				mystack.push(temp);
				sum += temp;
			}
			else if (ops[i] == "+")
			{
				int temp1 = mystack.top();
				mystack.pop();
				int temp2 = mystack.top();
				temp2 += temp1;
				mystack.push(temp1);
				mystack.push(temp2);
				sum += temp2;
			}
			else
			{
				int i_auto = std::stoi(ops[i],nullptr,0);
				mystack.push(i_auto);
				sum += i_auto;
			}
		}
		return sum;
    }
};
int main()
{}
