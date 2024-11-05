/*******************************************************************************
 *      file name: longest_subsequence_with_limited_sum.best.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/05-11:11                                    
 * modified time: 24/11/05-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        vector<int> ans;
        int sum = 0;
        ans.push_back(0);
        for (auto n : nums) {
            sum += n;
            ans.push_back(sum);
        }
        for (auto q: queries) {
            int i = bs(q, ans);
            //if (i != 0) i++;
            res.push_back(i);
        }
        return res;
    }

    int bs(int val, vector<int>& vec) {
        int ret = 0, i = 0, j = vec.size()-1, mid = 0;
        while(i <= j) {
            mid = (i+j)/2;
            //cout<<"i:"<<i<<",j:"<<j<<",mid:"<<mid<<endl;
            if (val >= vec[mid]) {
                ret = mid;
                i = mid+1;
            }
            else j = mid-1;
        }
        return ret;
    }
};
