/*******************************************************************************
 *      file name: xor_operation_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/21-20:14:22                              
 *  modified time: 2021/11/21-20:14:22                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret = ret^(start+2*i);
        }
        return ret;
    }
};
int main()
{}
