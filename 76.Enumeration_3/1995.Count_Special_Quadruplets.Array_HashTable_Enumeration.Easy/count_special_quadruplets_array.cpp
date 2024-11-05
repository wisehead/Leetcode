/*******************************************************************************
 *      file name: count_special_quadruplets_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/05-11:11                                    
 * modified time: 24/11/05-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ret = 0;
        //sort(nums.begin(), nums.end());
        unordered_map<int,int> ht;
        int n = nums.size();
        int maxn = nums[0];
        for (auto x : nums) {
            ht[x]++;
            maxn = max(maxn, x);
        }

        for (int i = 0; i < n-3; i++) {
            for(int j = i+1; j < n-2; j++) {
                for (int k = j+1; k < n-1; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    // cout<<"i:"<<i<<",j:"<<j<<",k:"<<k<<endl;
                    // cout<<"i:"<<nums[i]<<",j:"<<nums[j]<<",k:"<<nums[k]<<",sum:"<<sum<<endl;
                    if (sum > maxn) continue;
                    if (!ht.count(sum)) continue;
                        //cout<<"i:"<<i<<",j:"<<j<<",k:"<<k<<endl;
                        //cout<<"i:"<<nums[i]<<",j:"<<nums[j]<<",k:"<<nums[k]<<",sum:"<<sum<<endl;
                        //ret += ht[sum];
                    for (int o = k+1; o < n; o++) {
                        if (sum == nums[o]) ret++;
                    }
                }
            }
        }
        return ret;
    }
};
