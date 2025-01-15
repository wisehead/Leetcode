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
        if (n<=1) {
            return 1;
        }
        vector<int> vec(n+1,0);
        vec[0] = 1;
        vec[1] = 1;
        for (int step = 2; step <= n; step++) {
            int res = 0;
            for (int i = 1; i <= step; i++) {
                int left = vec[i-1];
                int right = vec[step-i];
                res += left* right;
            }
            vec[step] = res;
        }
        return vec[n];
    }
};
int main()
{}
