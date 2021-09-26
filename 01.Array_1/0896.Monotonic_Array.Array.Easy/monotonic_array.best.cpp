/*******************************************************************************
 *      file name: monotonic_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/15-19:24:05                              
 *  modified time: 2019/01/15-19:24:05                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
        return inc || dec;
    }
};
int main()
{}
