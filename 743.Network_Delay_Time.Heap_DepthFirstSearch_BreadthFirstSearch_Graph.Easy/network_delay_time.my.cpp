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
		cost[K] = 0;
		set<int> s;
		s.insert(K);
		set<int>::iterator iter;
		while (!s.empty())
		{
			set<int> temp_s = s;
			for(iter = temp_s.begin(); iter != temp_s.end(); iter++)
			{
				int current_node = *iter;
				s.erase(current_node);
				int current_cost = cost[current_node];
                cout<<"current_node:"<<current_node<<"  current_cost:"<<current_cost<<endl;
				vector<vector<int> > temp_times = times;
				for (int i = 0; i < temp_times.size(); i++)
				{
					vector<int> rec = temp_times[i];
					if (rec[0] == current_node)
					{
						int dest_node = rec[1];
						int new_cost = rec[2];
						if (cost.count(dest_node))
						{
							int old_cost = cost[dest_node];
							if (current_cost + new_cost < old_cost)
							{
								cost[dest_node] = current_cost+ new_cost;
                                cout<<"rec:"<<rec[0]<<" "<<rec[1]<<"    "<<rec[2]<<endl;
                                cout<<"update:  dest_node:"<<dest_node<<"  cost[dest_node]:"<<cost[dest_node]<<endl;
                                s.insert(dest_node);
							}
						}
						else
						{
							cost[dest_node] = current_cost + new_cost; 
                            cout<<"new: dest_node:"<<dest_node<<"  cost[dest_node]:"<<cost[dest_node]<<endl;
							s.insert(dest_node);
						}
						//temp_times.erase(temp_times.begin() + i);
						//i--;
					}
				}
			}
		}
		map<int, int>::iterator miter;
		int max_time = 0;
		for(miter = cost.begin(); miter != cost.end(); miter++)
		{
            cout<<"miter->first:"<<miter->first<<"  miter->second:"<<miter->second<<endl;
			if (miter->second > max_time) 
				max_time = miter->second;
		}
        if (max_time > 0 && cost.size() == N)
    		return max_time;
        return -1;
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
