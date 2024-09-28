/*******************************************************************************
 *      file name: find_the_town_judge.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/12/31-22:07:44                              
 *  modified time: 2019/12/31-22:07:44                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;
        unordered_map<int, int> be_trusted;
        unordered_map<int, int> trusted;
        for (auto v : trust) {
            be_trusted[v[1]]++;
            trusted[v[0]]++;
        }
        for (auto it = be_trusted.begin(); it != be_trusted.end(); it++) {
            if (it->second == n-1 && trusted[it->first] == 0) return it->first;
        }
        return -1;
    }
};
