/*******************************************************************************
 *      file name: unique_binary_search_trees.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/02-18:36:03                              
 *  modified time: 2021/10/02-18:36:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        return dfs(n);
    }
    int dfs(int n) {
        int res = 0;
        if (n<=1) {
            return 1;
        }
        
        if (mp.count(n)) return mp[n];
        for (int i = 1; i <= n; i++) {
            int left = dfs(i-1);
            int right = dfs(n-i);
            res += left* right;
        }
        mp[n] = res;
        return res;        
    }
private:
    map<int,int> mp;
};
int main()
{}
