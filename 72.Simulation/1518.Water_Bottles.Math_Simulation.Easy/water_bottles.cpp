/*******************************************************************************
 *      file name: water_bottles.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/29-10:16:48                              
 *  modified time: 2021/11/29-10:16:48                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int n = numBottles;
        while (n >= numExchange) {
            int x = n / numExchange;
            int c = n % numExchange;
            n = x + c;
            res += x;
        }
        return res;
    }
};
int main()
{}
