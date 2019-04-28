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
		for (int i = size - 1; i >= 0 && i >= size - n; i--)
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
		map<int,char>::reverse_iterator it3;

		while (!m3.empty())
		{
            for (it3 = m3.rbegin(); it3 != m3.rend(); )
            {	
                map<int,char>::reverse_iterator it4 = it3;
    			char task = it4->second;
                //cout<<"task:"<<task<<endl;
			    while (it4 != m3.rend() && conflict(vec, n, task))
				    it4++;
			    if (it4 != m3.rend())
			    {
				    vec.push_back(task);
				    int cnt = it4->first;
				    map<int,char>::iterator tmp_it;
				    tmp_it = m3.find(cnt);
				    while(tmp_it->second != task)
				    	tmp_it++;
			    	m3.erase(tmp_it);
				    cnt--;
				    if (cnt > 0)
				    {
					    m3.insert(make_pair(cnt, task));
				    }
                    break;
			    }
                if (++it3 == m3.rend())
                    vec.push_back('1');
            }

            //printvec(vec);
		}
		return vec.size();
    }
};
int main()
{
	Solution sol;
	char arr[] = {'A','A','A','B','B','B'};
	vector<char> vec(arr, arr+6);
	int n = 2;
	int ret = sol.leastInterval(vec, n);
}
