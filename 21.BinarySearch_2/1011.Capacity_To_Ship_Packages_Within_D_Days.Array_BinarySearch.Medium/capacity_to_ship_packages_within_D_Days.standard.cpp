/*******************************************************************************
 *      file name: capacity_to_ship_packages_within_D_Days.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/13-15:06:01                              
 *  modified time: 2019/07/13-15:06:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Given the number of bags,
return the minimum capacity of each bag,
so that we can put items one by one into all bags.

Similar as
875. Koko Eating Bananas
774. Minimize Max Distance to Gas Station
 */
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 25000000;
        for (int w: weights)
            left = max(left, w);
        while (left < right) {
            int mid = (left + right) / 2, need = 1, cur = 0;
            for (int i = 0; i < weights.size() && need <= D; cur += weights[i++])
                if (cur + weights[i] > mid)
                    cur = 0, need++;
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
int main()
{}
