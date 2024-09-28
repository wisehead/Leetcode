/*******************************************************************************
 *      file name: find_subsequence_of_length_k_with_the_largest_sum.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/28- 9:09                                    
 * modified time: 24/09/28- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> res;
        map<int, int> ht;
        // vector<vector<int>> vv;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                pq.push({nums[i],i});
            } else {
                auto v = pq.top();
                if (nums[i] > v[0]) {
                    pq.pop();
                    pq.push({nums[i],i});
                }
            }
        }

        int cnt = 0;
        while (cnt<k) {
            auto v = pq.top();
            cout<<"v[0]"<<v[0]<<",v1:"<<v[1]<<endl;
            pq.pop();
            cnt++;
            ht[v[1]] = v[0];
            //res[v[1]] = v[0];
        }

        for (auto it = ht.begin(); it != ht.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
