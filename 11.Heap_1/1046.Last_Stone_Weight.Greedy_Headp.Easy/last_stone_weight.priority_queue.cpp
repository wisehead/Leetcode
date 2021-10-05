/*******************************************************************************
 *      file name: last_stone_weight.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/26-19:10:13                              
 *  modified time: 2020/09/26-19:10:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto e : stones) {
            pq.push(e);
        }
        while (pq.size() > 1) 
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int r = (x-y);
            if (r) pq.push(r);
        }
        
        if (pq.empty()) return 0;
        return pq.top();
    }
};
int main()
{}
