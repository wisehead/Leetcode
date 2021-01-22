/*******************************************************************************
 *      file name: find_n_unique_integers_sum_up_to_zero.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2021/01/22-20:20:33                              
 *  modified time: 2021/01/22-20:20:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if (n % 2) res.push_back(0);
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            res.push_back(i+1);
            res.push_back(-i-1);
        }
        return res;
    }
};
int main()
{}
