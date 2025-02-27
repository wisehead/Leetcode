/*******************************************************************************
 *      file name: beautiful_arrangement.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/09- 1:01                                    
 * modified time: 25/01/09- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool seen[16] = {};
    int res = 0;
    int dfs(int n, int pos = 1) {
        if (pos > n) return res++;
        for (int i = 1; i <= n; i++) {
            if (!seen[i] && (i % pos == 0 || pos % i == 0)) {
                // marking i as seen
                seen[i] = true;
                dfs(n, pos + 1);
                // backtracking
                seen[i] = false;
            }
        }
        return res;
    }
    int countArrangement(int n) {
        if (n < 4) return n;
        return dfs(n);
    }
};
