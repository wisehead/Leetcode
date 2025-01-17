/*******************************************************************************
 *      file name: fair_distribution_of_cookies.bt.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/17- 1:01                                    
 * modified time: 25/01/17- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int min_v;
    int k;
    unordered_map<int,int> vv;
    int n;
    int distributeCookies(vector<int>& cookies, int x) {
        k = x;
        min_v = INT_MAX;
        n = cookies.size();
        bt(cookies,0);
        return min_v;
    }

    int get_max() {
        int max_v = 0;
        for (auto it : vv) {
            max_v = max(max_v, it.second);
        }
        return max_v;
    }

    void bt(vector<int>& cookies, int i) {
        if (i >= n) {
            int max_v = get_max();
            min_v = min(min_v, max_v);
            return;
        }

        for (int j = 0; j < k; j++) {
            vv[j] += cookies[i];
            if (vv[j] >= min_v) {
                vv[j] -= cookies[i];
                continue;
            }
            bt(cookies, i+1);
            vv[j] -= cookies[i];
        }
    }
};
