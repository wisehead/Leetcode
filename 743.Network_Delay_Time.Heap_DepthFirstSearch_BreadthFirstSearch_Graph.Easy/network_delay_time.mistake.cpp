/*******************************************************************************
 *      file name: network_delay_time.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/05-11:43:04                              
 *  modified time: 2018/11/05-11:43:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int> >& times, int N, int K) {
		if (K > N) return -1;
		map<int, int> cost;
		cost[K-1] = 0;
		set<int> s;
		s.insert(K-1);
		//map<int, int>::iterator iter;
		set<int>::iterator iter;
		while (!s.empty())
		{
			set<int> temp_s = s;
			for(iter = temp_s.begin(); iter != temp_s.end(); iter++)
			{
				int current_node = *iter;
				s.erase(current_node);
				int current_cost = cost[current_node];
				vector<int> sources = times[current_node];
				for (int j = 0; j < sources.size() && j < N; j++)
				{
					int new_cost = sources[j];
					if (cost.count(j))
					{
						int old_cost = cost[j];
						if (current_cost + new_cost < old_cost)
						{
							cost[j] = current_cost+ new_cost;
						}
					}
					else
					{
						cost[j] = current_cost + new_cost; 
						s.insert(j);
					}
				}
			}
		}
		map<int, int>::iterator miter;
		int max_time = 0;
		for(miter = cost.begin(); miter != cost.end(); miter++)
		{
			if (miter->second > max_time) 
				max_time = miter->second;
		}
		return max_time;
    }
};
int main()
{
	Solution sol;
	int arr[3] = {1,2,1};
	vector<int> vec(arr, arr+3);
	vector<vector<int> > input; 
	input.push_back(vec);
	int N = 2;
	int K = 1;
	int ret = 0;
	ret = sol.networkDelayTime(input, N, K);
	cout<<"ret:"<<ret<<endl;
}
