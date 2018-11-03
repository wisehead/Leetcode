/*******************************************************************************
 *      file name: reach_a_number.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/19-19:11:58                              
 *  modified time: 2018/10/19-19:11:58                              
 *******************************************************************************/
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int reachNumber(int target) {
		set<int> s;
		int i = 1;
		while (1)
		{
			set<int>::iterator iter;
			set<int> s2;
			for(iter = s.begin() ; iter != s.end() ; ++iter)
			{
				int temp1 = *iter + i;
				cout<<"i:"<<i<<"	temp1:"<<temp1<<endl;
				s2.insert(temp1);
				int temp2 = *iter - i;
				cout<<"i:"<<i<<"	temp2:"<<temp2<<endl;
				s2.insert(temp2);
			}
			s = s2;
			//cout<<"i:"<<i<<"	*iter:"<<*iter<<endl;
			if (i==1)
			{
				s.insert(1);
				s.insert(-1);
			}
			if (s.count(target)) return i;
			i++;
		}
		return i;
    }
};
int main()
{
	Solution sol;
	//int ret = sol.reachNumber(3);
	//int ret = sol.reachNumber(2);
	int ret = sol.reachNumber(1);
	cout<<"ret:"<<ret<<endl;
}
