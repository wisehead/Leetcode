/*******************************************************************************
 *      file name: hamming_distance.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/20-21:02:36                              
 *  modified time: 2018/07/20-21:02:36                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};

int main()
{}
