/*******************************************************************************
 *      file name: smallest_range_I.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/18-19:02:25                              
 *  modified time: 2019/01/18-19:02:25                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int> A, int K) {
        int mx = A[0], mn = A[0];
        for (int a : A) mx = max(mx, a), mn = min(mn, a);
        return max(0, mx - mn - 2 * K);
    }
};
int main()
{}
