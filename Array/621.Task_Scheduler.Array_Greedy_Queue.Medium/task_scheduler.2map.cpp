/*******************************************************************************
 *      file name: task_scheduler.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/28-10:35:59                              
 *  modified time: 2019/04/28-10:35:59                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
	void printvec(vector<char>& vec) {
		for (auto e : vec)
			cout<<e<<",";
		cout<<endl;
	}
	bool conflict(vector<char>& vec, int n, char x) {
		int size = vec.size();
		for (int i = size - 1; i >= 0 && i > size - 1 - n; i--)
		{
			if (vec[i] == x) return true;
		}
		return false;
	}
    int leastInterval(vector<char>& tasks, int n) {
		map<char, int> mm;
		map<int, char> m2;
		vector<char> vec;
		for (auto e : tasks)
		{
			if (mm.count(e))
				mm[e]++;
			else
				mm[e] = 1;
		}
		map<char, int>::iterator it;
		for (it = mm.begin(); it != mm.end(); it++)
			m2[it->second] = it->first;
		map<int,char>::reverse_iterator it2;

		while (!m2.empty())
		{
			it2 = m2.rbegin();
			char task = it2->second;
            cout<<"task:"<<task<<endl;
			while (it2 != m2.rend() && conflict(vec, n, task))
				it2++;
			if (it2 != m2.rend())
			{
				vec.push_back(task);
				int cnt = it2->first;
				cnt--;
				m2.erase(it2);
				if (cnt > 0)
				{
					m2[cnt] = task;
				}
			}
			else
			{
				vec.push_back('1');
			}
            printvec(vec);
		}
		return vec.size();
    }
};
int main()
{}
