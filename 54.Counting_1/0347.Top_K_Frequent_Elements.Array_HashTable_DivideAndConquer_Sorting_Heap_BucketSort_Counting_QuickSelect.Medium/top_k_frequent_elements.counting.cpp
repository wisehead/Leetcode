/*******************************************************************************
 *      file name: top_k_frequent_elements.sort.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/05-10:49:28                              
 *  modified time: 2021/10/05-10:49:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto p : m)
            buckets[p.second].push_back(p.first);

        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};
int main()
{}
