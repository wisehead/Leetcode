/*******************************************************************************
 *      file name: minimum_cost_to_move_chips_to_the_same_position.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-14:54:53                              
 *  modified time: 2020/10/29-14:54:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a = 0, b = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i]%2 == 0) ++a;
            else ++b;
        }
        
        return min(a,b);
    }
};
int main()
{}
