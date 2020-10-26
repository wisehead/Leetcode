/*******************************************************************************
 *      file name: gray_code.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/26-17:34:27                              
 *  modified time: 2020/10/26-17:34:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;
class Solution {
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        }
        else {
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};
int main()
{}
