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
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        
        while (stones.size() > 1)
        {
            int size = stones.size();
            int x = abs(stones[size - 1] - stones[size - 2]);
            stones.pop_back();
            if (stones.size() == 1) {
                stones[0] = x;
                continue;
            }
            
            if (x == 0) {
                stones.pop_back();
                continue;
            }            

            if (stones.size() > 1)
            {
                int i = stones.size() - 2;
                for (; i >= 0; i--)
                {
                    if (stones[i] > x) stones[i+1] = stones[i];
                    else break;
                }
                stones[i+1] = x;
            }
        }
        return stones[0];
    }
};
int main()
{}
