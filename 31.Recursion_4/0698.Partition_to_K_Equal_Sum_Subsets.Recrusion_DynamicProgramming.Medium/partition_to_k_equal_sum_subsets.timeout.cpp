/*******************************************************************************
 *      file name: partition_to_k_equal_sum_subsets.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-11:08:00                              
 *  modified time: 2020/10/29-11:08:00                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto e : nums) sum += e;
        if (sum % k != 0) return false;
        int avg = sum / k;
        //sort(nums.begin(), nums.end());
        //reverse(nums.begin(), nums.end());
        vector<int> vec(k,0);
        return dfs(vec, nums, 0, avg, k);
    }
    
    bool dfs(vector<int>& vec, vector<int>& nums, int start, int avg, int k) {
        /*
        cout<<"start:"<<start<<endl;
        for (auto e : vec) {
            cout<<"e:"<<e<<endl;
        }
        cout<<endl;
        */
        
        int size = nums.size();
        if (start == size) {
        //cout<<"start:"<<start<<endl;
        for (auto e : vec) {
            if (e != avg) return false;
            //cout<<"e:"<<e<<endl;
        }
        //cout<<endl;            
            return true;
        } 
            
        for (int i = start; i < size; i++) {
            for (int j = 0; j < k; j++) {
                vec[j] += nums[i];
                if (vec[j] <= avg) {
                    if (dfs(vec, nums, i+1, avg, k)) return true;
                }
                vec[j] -= nums[i];
            }
        }
        return false;
    }

};
int main()
{}
