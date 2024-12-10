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
        map<int,int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            vector<int> v;
            cout<<"first:"<<it->first<<", it->second:"<<it->second<<endl;
            v.push_back(it->second);
            v.push_back(it->first);
            vec.push_back(v);
        }
        sort(vec.begin(), vec.end());
        int x = 0;
        for (int i = vec.size()-1; i >= 0&& x <k; i--, x++) {
            res.push_back(vec[i][1]);
        }

        return res;
    }
};
int main()
{}
