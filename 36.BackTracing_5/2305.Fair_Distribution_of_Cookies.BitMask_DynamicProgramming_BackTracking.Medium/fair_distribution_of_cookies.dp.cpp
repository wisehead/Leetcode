/*******************************************************************************
 *      file name: fair_distribution_of_cookies.dp.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/17- 1:01                                    
 * modified time: 25/01/17- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<vector<int>> dp;
    int full_mask;
    int n;
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        full_mask = pow(2,n) - 1;
        dp.resize(k+1, vector<int>(pow(2,n),-1));
        int mask = 0;
        int ret = bt(cookies, mask, k);
        return ret;
    }

    int count_sum(vector<int>& cookies, int bitmap) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (bitmap & (1<<i)) {
                cnt += cookies[i];
            }
        }
        return cnt;
    }

    int bt(vector<int>& cookies, int mask, int k) {
        if (dp[k][mask] != -1) {
            return dp[k][mask];
        }

        if (k == 1) {
            dp[k][mask] = count_sum(cookies, mask ^ full_mask);
            return dp[k][mask];
        }

        int min_v = INT_MAX;
        for (int i = 1; i < pow(2,n); i++) {
            if (i & mask) continue;
            int cnt = count_sum(cookies, i);
            int new_mask = (mask | i);
            int ret = bt(cookies, new_mask, k - 1);
            min_v = min(min_v, max(cnt, ret));
        }
        dp[k][mask] = min_v;
        return min_v;
    }
};
