/*******************************************************************************
 *      file name: sort_array_by_parity.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/17-10:53:23                              
 *  modified time: 2019/01/17-10:53:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }
};
int main()
{}
