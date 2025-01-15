/*******************************************************************************
 *      file name: palindromic_substrings.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/15- 1:01                                    
 * modified time: 25/01/15- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-i; j++) {
                if (i == 0) {
                    dp[i][j] = true;
                    cnt++;
                    continue;
                }
                if (i == 1) {
                    if (s[j] == s[j+i]) {
                        dp[i][j] = true;
                        cnt++;
                    }
                    continue;
                }
                if (s[j] != s[j+i]) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = dp[i-2][j+1];
                    if (dp[i][j]) cnt++;
                }
            }

        }
        return cnt;
    }
};
