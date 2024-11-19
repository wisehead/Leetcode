/*******************************************************************************
 *      file name: water_and_jug_problem.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/27-14:14:55                              
 *  modified time: 2021/12/27-14:14:55                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        return dfs(jug1Capacity, jug2Capacity, targetCapacity);
    }
    bool dfs(int a, int b, int c) {
        if (c % a == 0 || c % b == 0) return true;

        if (a > b) {
            return dfs(b, a-b, c);
        } else if (a < b) {
            return dfs(a, b - a, c);
        }        
        return false;
    }
};
int main()
{}
