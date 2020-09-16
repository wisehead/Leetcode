/*******************************************************************************
 *      file name: grumpy_bookstore_owner.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/16-21:02:44                              
 *  modified time: 2020/01/16-21:02:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxSatisfied(vector<int>& cs, vector<int>& grumpy, int X) {
		auto satisfied = 0, m_add_satisfied = 0, add_satisfied = 0;
		for (auto i = 0; i < cs.size(); ++i) {
			satisfied += grumpy[i] ? 0 : cs[i];
			add_satisfied += grumpy[i] ? cs[i] : 0;
			if (i >= X) add_satisfied -= grumpy[i - X] ? cs[i - X] : 0;
			m_add_satisfied = max(m_add_satisfied, add_satisfied);
		}
		return satisfied + m_add_satisfied;
	}
};
int main()
{

//customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
}
