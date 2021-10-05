/*******************************************************************************
 *      file name: top_k_frequent_elements.sort.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/05-10:49:28                              
 *  modified time: 2021/10/05-10:49:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto e : nums) {
            if (mp.count(e)) mp[e]++;
            else mp[e] = 1;
        }

        vector<int> res;
        vector<vector<int>> vec;
        priority_queue<vector<int>, vector<vector<int>>> pq;
        map<int,int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }
        int x = 0;
        while(!pq.empty() && x < k)
        {
            res.push_back(pq.top()[1]);
            pq.pop();
            x++;
        }

        return res;
    }
};
int main()
{}
