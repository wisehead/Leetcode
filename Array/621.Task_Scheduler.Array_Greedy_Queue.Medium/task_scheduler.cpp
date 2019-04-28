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
		multimap<int, char> m3;
		for (it = mm.begin(); it != mm.end(); it++)
		{
			m3.insert(make_pair(it->second, it->first));
		}
		/*
		for (it = mm.begin(); it != mm.end(); it++)
			m2[it->second] = it->first;
			*/
		map<int,char>::iterator it3;

		while (!m3.empty())
		{
			it3 = m3.begin();
			char task = it3->second;
            cout<<"task:"<<task<<endl;
			while (it3 != m3.end() && conflict(vec, n, task))
				it3++;
			if (it3 != m3.end())
			{
				vec.push_back(task);
				int cnt = it3->first;
				cnt--;
				m3.erase(it3);
				if (cnt > 0)
				{
					m3.insert(make_pair(cnt, task));
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
