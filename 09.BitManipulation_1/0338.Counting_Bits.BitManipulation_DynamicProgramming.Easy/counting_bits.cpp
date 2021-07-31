/*******************************************************************************
 *      file name: counting_bits.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-11:17:25                              
 *  modified time: 2021/07/31-11:17:25                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int get_bits(int n) {
        int N = 17;
        unsigned long long mask = 1;
        int cnt = 0;
        for (int i = 0; i < N; i++){
            if (n & mask) ++cnt;
            mask = mask<<1;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(get_bits(i));
        }
        return res;
    }
};
int main()
{}
