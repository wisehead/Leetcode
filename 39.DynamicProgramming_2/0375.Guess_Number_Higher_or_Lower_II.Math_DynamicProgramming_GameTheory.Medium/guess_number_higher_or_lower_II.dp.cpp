/*******************************************************************************
 *      file name: guess_number_higher_or_lower_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/25-11:17:35                              
 *  modified time: 2021/08/25-11:17:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int step = 1; step < n; step++) {
            for (int i = 1; i <= n -step; i++) {
                int x = min(i+dp[i+1][i+step], i+step+dp[i][i+step-1]);
                for (int j = i+1;j <= i+ step-1; j++) {
                    int temp = j+ max(dp[i][j-1], dp[j+1][i+step]);
                    if (temp < x) x = temp;
                }
                dp[i][i+step] = x;
            }
        }
        return dp[1][n];
    }
};
int main()
{}
