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
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& A) {
        priority_queue<int> pq(begin(A), end(A));
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x > y) pq.push(x - y);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
int main()
{}
