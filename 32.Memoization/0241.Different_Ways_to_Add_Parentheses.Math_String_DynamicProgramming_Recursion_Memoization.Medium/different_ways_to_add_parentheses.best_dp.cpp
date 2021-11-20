/*******************************************************************************
 *      file name: different_ways_to_add_parentheses.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/19-11:43:33                              
 *  modified time: 2021/08/19-11:43:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
vector<int> diffWaysToCompute(string expression) {
        vector<char> op;
        vector<int> v;
        for(int i = 0; i < expression.length(); ){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                op.push_back(expression[i]);
                i++;
            }
            else{
                string s = "";
                while(i < expression.length() && isdigit(expression[i])){
                    s += expression[i];
                    i++;
                }
                v.push_back(stoi(s));
            }
        }
        int n = v.size();
        vector<vector<multiset<int>>> dp(n + 1, vector<multiset<int>>(n + 1));
        for(int i = 0; i < n; i++){
            multiset<int> s;
            s.insert(v[i]);
            dp[i][i] = s;
        }
        int m = op.size();
        for(int len = 1; len < n; len++){
            for(int left = 0; left + len < n; left++){
                int right = left + len;
                multiset<int> s;
                for(int k = left; k < right; k++){
                    int z;
                    for(auto x : dp[left][k]){
                        for(auto y : dp[k + 1][right]){
                            if(op[k] == '*')
                                z = x * y;
                            else if(op[k] == '+'){
                                z = x + y;
                            }
                            else
                                z = x - y;
                            s.insert(z);
                        }
                    }

                    dp[left][right] = s;
                }
            }
        }
        vector<int> ans;
        for(auto i : dp[0][n - 1]) ans.push_back(i);
        return ans;
    }
};
int main()
{}
